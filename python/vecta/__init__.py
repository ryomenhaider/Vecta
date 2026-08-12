from vecta import _vecta

__version__ = "0.0.3"


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


def _coerce(m):
    if isinstance(m, Matrix):
        return m._m
    if isinstance(m, _vecta.Matrix):
        return m
    raise TypeError(f"expected a Matrix, got {type(m).__name__}")


def array(rows):
    return Matrix(rows)


def zeros(shape):
    return Matrix(int(shape[0]), int(shape[1]))


def ones(shape):
    return Matrix(int(shape[0]), int(shape[1]), 1.0)


def eye(n):
    return _wrap_identity(n)


def identity(n):
    return _wrap_identity(n)


def _wrap_identity(n):
    return Matrix._wrap(_vecta.identity(n))


def matmul(A, B):
    return Matrix._wrap(_vecta.matmul(_coerce(A), _coerce(B)))


def add(A, B):
    return Matrix._wrap(_vecta.add(_coerce(A), _coerce(B)))


def scalar_mul(A, k):
    return Matrix._wrap(_vecta.scalar_mul(_coerce(A), k))


def transpose(A):
    return Matrix._wrap(_vecta.transpose(_coerce(A)))


def is_symmetric(A):
    return _vecta.is_symmetric(_coerce(A))


__all__ = [
    "Matrix",
    "array",
    "zeros",
    "ones",
    "eye",
    "identity",
    "matmul",
    "add",
    "scalar_mul",
    "transpose",
    "is_symmetric",
]
