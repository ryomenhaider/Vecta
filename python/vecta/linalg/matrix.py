from vecta import _vecta

class Matrix:
    def __init__(self, *args):
        if len(args) == 1 and isinstance(args[0], (list, tuple)):
            self._m = _vecta.Matrix([list(r) for r in args[0]])
        elif len(args) in (2, 3) and isinstance(args[0], int) and isinstance(args[1], int):
            self._m = _vecta.Matrix(args[0], args[1], *args[2:])
        else:
            raise TypeError(
                "Matrix expects a nested list (Matrix([[1, 2], [3, 4]])) "
                "or dimensions (Matrix(rows, cols, init=0.0))"
            )

    @classmethod
    def _wrap(cls, m):
        out = cls.__new__(cls)
        out._m = m
        return out

    @property
    def shape(self):
        return (self._m.rows(), self._m.cols())

    @property
    def T(self):
        return self._wrap(_vecta.transpose(self._m))

    def _resolve(self, key):
        if not isinstance(key, tuple) or len(key) != 2:
            raise TypeError("index must be a pair of ints, e.g. A[0, 1]")
        i, j = key
        rows, cols = self.shape
        if not isinstance(i, int) or not isinstance(j, int):
            raise TypeError("index must be a pair of ints, e.g. A[0, 1]")
        if i < 0:
            i += rows
        if j < 0:
            j += cols
        if not (0 <= i < rows and 0 <= j < cols):
            raise IndexError("matrix index out of range")
        return i, j

    def __getitem__(self, key):
        i, j = self._resolve(key)
        return self._m(i, j)

    def __setitem__(self, key, value):
        i, j = self._resolve(key)
        self._m.set(i, j, value)

    def __repr__(self):
        rows = []
        for i in range(self._m.rows()):
            row = ", ".join(repr(self._m(i, j)) for j in range(self._m.cols()))
            rows.append("[" + row + "]")
        return "[" + ", ".join(rows) + "]"

    __str__ = __repr__
