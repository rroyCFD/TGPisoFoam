// Velocity error norms--------------------------------------------------------------//
Info << "Calculating Uerror" << endl;
Uerror = Ustart*Foam::exp(-2.0*nu.value()*runTime.value()) - U;

dimensionedScalar ULinfErr = max(mag(Uerror));          // infinity norm
dimensionedScalar UL2err   = sqrt(sum(magSqr(Uerror))); // 2nd norm

// Pressure error norms ----------------------------------------------------------//
Info << "Calculating perror" << endl;
pRefValueAna  = sqr(Uinit)* 0.25*(
                  Foam::cos(2.*xPRefCell/L.value())
                + Foam::cos(2.*yPRefCell/L.value()) )
                * Foam::exp(-4.*nu.value()*runTime.value());

Info << "Analytical value at pRefCell: "<< pRefValueAna.value() << endl; 

perror = pstart*Foam::exp(-4.0*nu.value()*runTime.value()) - pRefValueAna - p;

dimensionedScalar pLinfErr = max(mag(perror));          // infinity norm
dimensionedScalar pL2err   = sqrt(sum(magSqr(perror))); // 2nd norm

Info << "L2   error norm | Velocity: " << UL2err.value()   << "\tPressure: " << pL2err.value()   << endl;
Info << "Linf error norm | Velocity: " << ULinfErr.value() << "\tPressure: " << pLinfErr.value() << endl;

Info << "Pressure decay coeffs: " << setprecision(10) << Foam::exp(-4.0*nu.value()*runTime.value()) << endl;
Info << "Velocity decay coeffs: " << setprecision(10) << Foam::exp(-2.0*nu.value()*runTime.value()) << endl;

// Check error at time=0
if (runTime.timeName() == "0")
{
    Uerror.write();
    perror.write();
}
//---------------------------------------------------------------//
//Weighted average norm
// scalar waUErr =errUsqr.weightedAverage(mesh.V()).value();
// Info << "Weighted Average Error: "<< waUErr <<endl;
    
