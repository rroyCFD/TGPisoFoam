// mesh coordinates
volScalarField x = mesh.C().component(vector::X);
volScalarField y = mesh.C().component(vector::Y);
volScalarField z = mesh.C().component(vector::Z); 

// //Initial Taylor Green field
// volVectorField Ustart = Uinit* 
//                         ( vector(1,0,0) * sin(x/L) * cos(y/L) * cos(z/L) 
//                         - vector(0,1,0) * cos(x/L) * sin(y/L) * cos(z/L) 
//                         + vector(0,0,1) * scalar(0.));
// 
// volScalarField pstart = sqr(Uinit)/16. 
//                         * (cos(2.*x/L) + cos(2.*y/L))
//                         * (cos(2.*z/L) + scalar(2.));

//Initial Taylor Green field
volVectorField Ustart = Uinit* 
                        ( vector(1,0,0) * sin(x/L) * cos(y/L)
                        - vector(0,1,0) * cos(x/L) * sin(y/L)
                        + vector(0,0,1) * scalar(0.));

volScalarField pstart = sqr(Uinit) * 4 * (cos(2.*x/L) + cos(2.*y/L));
