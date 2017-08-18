dimensionedScalar epsilon
(
    "epsilon",
    dimensionSet(0, 0, 0, 0, 0),
    0.0
);

dimensionedScalar Ek
(
    "Ek",
    dimensionSet(0, 0, 0, 0, 0),
    0.0
);

dimensionedScalar tc
(
    "tc",
    dimensionSet(0, 0, 1, 0, 0),
    0.0
);
tc = L/Uinit;

OFstream outFile
(
    runTime.path()/"output.dat"
);

if (Pstream::parRun())
    {
        OFstream outFile
        (
            runTime.path()/".."/"output.dat"
        );
    }

