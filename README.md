# pitch-moment-coefficient
A C++ program that calculates pitching moment coefficients.

To find the coefficients, you need to use the algebraic method of factoring. This involves factoring the polynomial into its component parts, and then solving for the coefficients. The numerical factors are multiplied by the variables.  

M_0 is the zero-lift pitching moment(x=0), M is the total pitching moment, M_alpha is the pitching moment due to angle of attack, M_q is the pitching moment due to change in angle of attack over time, M_u is the pitching moment due to pitch rate, and M_de is the pitching moment due to elevator angle. 

M_0 is equated from the defined equation for finding pitching moment(M). M_alpha equation calculates the value of the Mth derivative of the function alpha, where alpha is the angle of attack. The equation is the mathematical representation of the Magnus effect where the force is perpendicular to the direction of the fluid's flow and to the axis of rotation. Same case for M_q, M_u, M_de with their respective functions. 

The error function is already defined smartly using calculus so its just replacing the equation with the variables estimated above. If the error is greater than the error tolerant, the error function is put to play.

The equation used is the result of an expansion of the function (1 - x)^-M around the point x = -M.
