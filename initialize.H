// Reynolds number
dimensionedScalar Re = Uinit*L/nu;
Info<< "\nInitializing Taylor-Greem Vortex flow with Re = "<< Re.value() << "\n" << endl;

// Intialize Velocity field
volScalarField x = mesh.C().component(vector::X);
volScalarField y = mesh.C().component(vector::Y);
volScalarField z = mesh.C().component(vector::Z); 

U  =  Uinit* 
    ( vector(1,0,0) * sin(x/L) * cos(y/L) 
    - vector(0,1,0) * cos(x/L) * sin(y/L) 
    + vector(0,0,1) * scalar(0.)) ;
U.correctBoundaryConditions();
Info<< "Writing field U" << endl;
U.write();

//Pressure-------------------------------------
p = sqr(Uinit)/4* (cos(2.*x/L) + cos(2.*y/L));

scalar xPRefCell = U.mesh().C()[pRefCell].x();
scalar yPRefCell = U.mesh().C()[pRefCell].y();

dimensionedScalar pRefValueAna  = sqr(Uinit)* 0.25*(
                                  Foam::cos(2.*xPRefCell/L.value())
                                + Foam::cos(2.*yPRefCell/L.value()) );
p =p - pRefValueAna;
p.correctBoundaryConditions();

Info<< "Writing field p" << endl;
p.write();


volVectorField Ustart = U;
volScalarField pstart = p;