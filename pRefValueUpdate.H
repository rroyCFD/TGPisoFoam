if (runTime.timeName() == runTime.startTime().name()) {
    Info << "x: " <<U.mesh().C()[pRefCell].x() << "\ty: " << U.mesh().C()[pRefCell].y() << endl;
    Info<< "Foam::cos(2.*U.mesh().C()[pRefCell].x()): " << Foam::cos(2.*Ustart.mesh().C()[pRefCell].x()) << endl;
    Info<< "Foam::cos(2.*U.mesh().C()[pRefCell].y()): " << Foam::cos(2.*Ustart.mesh().C()[pRefCell].y()) << endl;
} else {
    dimensionedScalar pRefValueNew = sqr(Uinit)* 0.25*(
                                      Foam::cos(2.*Ustart.mesh().C()[pRefCell].x()/L.value())
                                    + Foam::cos(2.*Ustart.mesh().C()[pRefCell].y()/L.value()) )
                                    * Foam::exp(-4.*nu.value()*runTime.value());

    pRefValue = pRefValueNew.value();
}

Info << "pRefValue: "<< pRefValue << endl; 

