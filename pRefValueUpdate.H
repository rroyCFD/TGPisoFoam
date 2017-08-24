dimensionedScalar pRefValueNew = sqr(Uinit)* 0.25*(
                                  Foam::cos(2.*U.mesh().C()[pRefCell].x()/L.value())
                                + Foam::cos(2.*U.mesh().C()[pRefCell].y()/L.value()) )
                                * Foam::exp(-4.*nu.value()*runTime.value());

pRefValue = pRefValueNew.value();
Info << "pRefValue: "<< pRefValue << endl; 