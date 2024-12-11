function [y] = Quat_Ops ( u );
q1=u(1);
q2=u(2);
q3=u(3);
q4=u(4);


y = 0.5*[q4 -q3 q2;
         q3 q4 -q1;
         -q2 q1 q4;
         -q1 -q2 -q3];


