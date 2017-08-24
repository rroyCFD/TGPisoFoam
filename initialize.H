if (init)
{
  // Reynolds number
  dimensionedScalar Re = Uinit*L/nu;
  Info<< "\nInitializing Taylor-Greem Vortex flow with Re = "<< Re << "\n" << endl;
  // Intialize Velocity field
  volScalarField x = mesh.C().component(vector::X);
  volScalarField y = mesh.C().component(vector::Y);
  volScalarField z = mesh.C().component(vector::Z); 
  
  U  =  Uinit* 
        ( vector(1,0,0) * sin(x/L) * cos(y/L) 
        - vector(0,1,0) * cos(x/L) * sin(y/L) 
        + vector(0,0,1) * scalar(0.)) ;
  U.correctBoundaryConditions();
  
  p = sqr(Uinit)/4* (cos(2.*x/L) + cos(2.*y/L));
  p.correctBoundaryConditions();
  
  
  Info<< "Writing field U" << endl;
  U.write();
  
  Info<< "Writing field p" << endl;
  p.write();
}