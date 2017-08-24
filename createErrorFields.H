// create error fields----------------------------//
#include "vector.H"

volVectorField Uerror
(
    IOobject
    (
        "Uerror",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::AUTO_WRITE
    ),
    //U
    mesh,
    dimensionedVector("Uerror",dimensionSet(0, 1, -1, 0, 0, 0, 0),vector::zero)
);

volScalarField perror
(
    IOobject
    (
        "perror",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::AUTO_WRITE
    ),
    //p
    mesh,
    dimensionedScalar("perror",dimensionSet(0, 2, -2, 0, 0, 0, 0), 0.0)
);

