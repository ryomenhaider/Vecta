from vecta import _vecta

Matrix = _vecta.Matrix
matmul = _vecta.matmul
add = _vecta.add
scalar_mul = _vecta.scalar_mul
transpose = _vecta.transpose
identity = _vecta.identity
is_symmetric = _vecta.is_symmetric

__version__ = "0.0.2"

__all__ = [
    "Matrix",
    "matmul",
    "add",
    "scalar_mul",
    "transpose",
    "identity",
    "is_symmetric",
]
