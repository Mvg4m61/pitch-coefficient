#include <iostream>
#include <cmath>
#include <array>

using namespace std;

int main()
{
    
    int num_experiments=0;
    double error_tolerant=0.000001;
    double step_size=0.1;
    
    
    
    double M_0=0; //pitching moment at zero angle of attack
    double M_alpha=0; //coefficient of the change of the angle of attack
    double M_q=0; //coefficient of the time rate of change of the angle of attack
    double M_u=0; //coefficient of the pitch rate
    double M_de=0; //coefficient of the change of the elevator angle
    
    double M=0; //pitching moment
    
    double error=0;
    
    double elevator_angle=0;
    double pitch_rate=0;
    double time_rate_change_angle=0;
    double angle_of_attack=0;
    
    cout<<"\nInput the value of the pitch moment: ";
    cin>>M;
    
    cout<<"\nInput the value of the elevator angle: ";
    cin>>elevator_angle;
    
    cout<<"\nInput the value of the pitch rate: ";
    cin>>pitch_rate;
    
    cout<<"\nInput the value of the time rate of change of the angle of attack: ";
    cin>>time_rate_change_angle;
    
    cout<<"\nInput the value of the angle of attack: ";
    cin>>angle_of_attack;
    
    M_0=M-(M_alpha*angle_of_attack+M_q*time_rate_change_angle+M_u*pitch_rate+M_de*elevator_angle);
M_alpha=(int)(pow((-1), (angle_of_attack-M)) * (pow(angle_of_attack, M)) / (1.0 * M * (M-angle_of_attack)));
M_q=(int)(pow((-1), (time_rate_change_angle-M)) * (pow(time_rate_change_angle, M)) / (1.0 * M * (M-time_rate_change_angle)));
M_u=(int)(pow((-1), (pitch_rate-M)) * (pow(pitch_rate, M)) / (1.0 * M * (M-pitch_rate)));
M_de=(int)(pow((-1), (elevator_angle-M)) * (pow(elevator_angle, M)) / (1.0 * M * (M-elevator_angle)));

error=M_0+M_alpha*angle_of_attack+M_q*time_rate_change_angle+M_u*pitch_rate+M_de*elevator_angle-M;
    
    num_experiments++;
    
    while (error>=error_tolerant)
    {
        cout<<"\nExperiment number: ";
        cin>>num_experiments;
        
        cout<<"\nInput the value of the pitch moment: ";
        cin>>M;
        
        cout<<"\nInput the value of the elevator angle: ";
        cin>>elevator_angle;
        
        cout<<"\nInput the value of the pitch rate: ";
        cin>>pitch_rate;
        
        cout<<"\nInput the value of the time rate of change of the angle of attack: ";
        cin>>time_rate_change_angle;
        
        cout<<"\nInput the value of the angle of attack: ";
        cin>>angle_of_attack;
        
        M_0=M_0-(step_size/num_experiments)*(M_0+M_alpha*angle_of_attack+M_q*time_rate_change_angle+M_u*pitch_rate+M_de*elevator_angle-M);
M_alpha=M_alpha-(step_size/num_experiments)*(M_0+M_alpha*angle_of_attack+M_q*time_rate_change_angle+M_u*pitch_rate+M_de*elevator_angle-M)*angle_of_attack;
M_q=M_q-(step_size/num_experiments)*(M_0+M_alpha*angle_of_attack+M_q*time_rate_change_angle+M_u*pitch_rate+M_de*elevator_angle-M)*time_rate_change_angle;
M_u=M_u-(step_size/num_experiments)*(M_0+M_alpha*angle_of_attack+M_q*time_rate_change_angle+M_u*pitch_rate+M_de*elevator_angle-M)*pitch_rate;
M_de=M_de-(step_size/num_experiments)*(M_0+M_alpha*angle_of_attack+M_q*time_rate_change_angle+M_u*pitch_rate+M_de*elevator_angle-M)*elevator_angle;
        
  error=(0.5*num_experiments)*((M_0+M_alpha*angle_of_attack+M_q*time_rate_change_angle+M_u*pitch_rate+M_de*elevator_angle-M)*(M_0+M_alpha*angle_of_attack+M_q*time_rate_change_angle+M_u*pitch_rate+M_de*elevator_angle-M));
        
        
        num_experiments++;
        
    }
    cout<<"\nPitch moment coefficient is "<<M_0;
    cout<<"\nAngle of attack coefficient is "<<M_alpha;
    cout<<"\nTime rate change coefficient is "<<M_q;
    cout<<"\nPitch rate coefficient is "<<M_u;
    cout<<"\nElevator angle coefficient is "<<M_de;
    cout<<"\n\nTerminating program...";
    
    return 0;
}
    
