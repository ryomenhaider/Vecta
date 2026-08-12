from vecta import _vecta
from python.vecta.linalg.matrix import Matrix

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