// Calculate error norm  
// Velocity error norms--------------------------------------------------------------//
volScalarField errUsqr = magSqr(Ustart*Foam::exp(-2*nu.value()*runTime.value()) - U); ///tc.value()
dimensionedScalar ULinfErr = sqrt(max(errUsqr));
dimensionedScalar UL2err = gSum(errUsqr);
UL2err = sqrt(UL2err);


// Pressure error norms ----------------------------------------------------------//
// volScalarField errp = magSqr(pstart*Foam::exp(-4*nu.value()*runTime.value()) - p);
volScalarField errp = sqr(pstart*Foam::exp(-4*nu.value()*runTime.value()) - p); ///tc.value()
dimensionedScalar pLinfErr = max(mag(errp));
dimensionedScalar pL2err = gSum(errp);
pL2err = sqrt(pL2err);

Info << "L2   error norm | Velocity: " << UL2err.value()   << "\tPressure: " << pL2err.value()   << endl;
Info << "Linf error norm | Velocity: " << ULinfErr.value() << "\tPressure: " << pLinfErr.value() << endl;
//---------------------------------------------------------------//
//Weighted average norm
// scalar waUErr =errUsqr.weightedAverage(mesh.V()).value();
// Info << "Weighted Average Error: "<< waUErr <<endl;
    
