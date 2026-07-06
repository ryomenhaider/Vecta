"""
Vecta: a from-scratch computational maths library for ML,
implemented in C++ with Python bindings.

Structured to follow "Mathematics for Machine Learning" (Deisenroth, Faisal, Ong):

Part I  - Mathematical Foundations
    linear_algebra, analytic_geometry, matrix_decompositions,
    vector_calculus, probability, optimization

Part II - Central Machine Learning Problems
    linear_regression, dimensionality_reduction,
    density_estimation, classification
"""
from . import linear_algebra
from . import analytic_geometry
from . import matrix_decompositions
from . import vector_calculus
from . import probability
from . import optimization
from . import linear_regression
from . import dimensionality_reduction
from . import density_estimation
from . import classification

__version__ = "0.0.1"
