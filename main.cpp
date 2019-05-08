//
//  main.cpp
//  SistemasOperativos-Algoritmos
//
//  Created by Vladi on 4/25/19.
//

#include<iostream>

using namespace std;

void rr()
{
    int i,n,time,remain,temps=0,time_quantum;
    int wt=0,tat=0;
    float at[10], bt[10], rt[10];
    
    cout<<" Ingrese Cantidad de procesos : ";
    cin>>n;
    remain=n;
    
    for(i=0;i<n;i++)
    {
        cout<<"\nTiempo de llegada P["<<i+1<<"] : ";
        cin>>at[i];
        cout<<"Ráfaga P["<<i+1<<"] : ";
        cin>>bt[i];
        rt[i]=bt[i];
    }
    
    cout<<"\n Quantum :";
    cin>>time_quantum;
    cout<<"\n\nProceso \t:Turnaround Time \tWaiting Time\n\n";
    for(time=0,i=0;remain!=0;)
    {
        if(rt[i]<=time_quantum && rt[i]>0)
        {
            time += rt[i];
            rt[i]=0;
            temps=1;
        }
        
        else if(rt[i]>0)
        {
            rt[i] -= time_quantum;
            time += time_quantum;
        }
        
        if(rt[i]==0 && temps==1)
        {
            remain--;
            printf("Process[%d]\t:\t%f\t:\t%f\n",i+1,time-at[i],time-at[i]-bt[i]);
            cout<<endl;
            
            wt += time-at[i]-bt[i];
            tat += time-at[i];
            temps=0;
        }
        
        if(i == n-1)
            i=0;
        else if(at[i+1] <= time)
            i++;
        else
            i=0;
    }
}

void fcfs(){
    
    float AT[10], RT[10], TT[10], WT[10], ABT[10];
    int num,i, j;
    int PID[10];
    float temp, temp1;
    int temp2;
   
    cout << " Ingrese cantidad de procesos : ";
    cin>>num;
    for (i=0; i<num; i++) {
        cout<<"\n Tiempo de llegada";
        cout<<" P["<<i+1<<"] : ";
        cin>>AT[i];
        cout<<" Ráfaga ";
        cout<<" P["<<i+1<<"] : ";
        cin>>RT[i];
        PID[i]=i+1;
    }
    
    cout<<"\n\n|Proceso|\t|Tiempo llegada|\t|Ráfaga|\n";
    for (i=0; i<num; i++) {
        cout<<"\tP["<<i+1<<"]"<<"\t\t\t"<<AT[i]<<"\t\t\t\t"<<RT[i]<<"\n";
    }
    
    for(i=0;i<=num ;i++)
    {
        for(j=i+1;j<num;j++)
        {
            if(AT[i]>AT[j])
            {
                temp2=PID[i];
                PID[i]=PID[j];
                PID[j]=temp2;
                
                temp1=AT[i];
                AT[i]=AT[j];
                AT[j]=temp1;
                
                temp=RT[i];
                RT[i]=RT[j];
                RT[j]=temp;
                
            }
        }
    }

    WT[0]=0;
    TT[0]=RT[0];
    ABT[0]=RT[0]+AT[0];
    for (i=1; i<num; i++) {
        
        ABT[i]=ABT[i-1]+RT[i];
        TT[i]=ABT[i]-AT[i];
        WT[i]=TT[i]-RT[i];
        
    }
    cout<<"\n \t\t\t ---- FCFS ---- ";
    cout<<"\n\n|Proceso|\t|Tiempo llegada|\t|Ráfaga|\t|T Time|\t|W Time|\n";
    for (i=0; i<num; i++) {
        
       cout<<"\tP["<<PID[i]<<"]"<<"\t\t\t"<<AT[i]<<"\t\t\t\t"<<RT[i]<<"\t\t\t"<<TT[i]<<"\t\t\t"<<WT[i]<<"\n";
        
    }
}

void priority(){
    
    float AT[10], RT[10], TT[10], WT[10], ST[10], PR[10], FT[10];
    int num,i, j;
    int PID[10];
    float temp, temp1, temp0;
    int temp2;
    
    cout << " Ingrese cantidad de procesos : ";
    cin>>num;
    for (i=0; i<num; i++) {
        cout<<"\n Tiempo de llegada";
        cout<<" P["<<i+1<<"] : ";
        cin>>AT[i];
        cout<<" Ráfaga ";
        cout<<" P["<<i+1<<"] : ";
        cin>>RT[i];
        cout<<" Prioridad ";
        cout<<" P["<<i+1<<"] : ";
        cin>>PR[i];
        PID[i]=i+1;
    }
    
    cout<<"\n\n|Proceso|\t|Tiempo llegada|\t|Ráfaga|\t|Prioridad|\n";
    for (i=0; i<num; i++) {
        cout<<"\tP["<<i+1<<"]"<<"\t\t\t"<<AT[i]<<"\t\t\t\t"<<RT[i]<<"\t\t\t\t"<<PR[i]<<"\n";
    }
    
    for(i=0;i<num ;i++)
    {
        for(j=0;j<num;j++)
        {
            if(PR[i]<PR[j])
            {
                temp2=PID[i];
                PID[i]=PID[j];
                PID[j]=temp2;
                
                temp0=PR[i];
                PR[i]=PR[j];
                PR[j]=temp0;
                
                temp1=AT[i];
                AT[i]=AT[j];
                AT[j]=temp1;
                
                temp=RT[i];
                RT[i]=RT[j];
                RT[j]=temp;
                
            }
        }
    }
    
    for(i=0;i<num;i++){
        
        if(i==0)
        {
            ST[i]=AT[i];
            WT[i]=ST[i]-AT[i];
            FT[i]=ST[i]+RT[i];
            TT[i]=FT[i]-AT[i];
        }
        else
        {
            ST[i]=FT[i-1];
            WT[i]=ST[i]-AT[i];
            FT[i]=ST[i]+RT[i];
            TT[i]=FT[i]-AT[i];
        }
    }
    cout<<"\n \t\t\t ---- Priority ---- ";
    cout<<"\n\n|Proceso|\t|Tiempo llegada|\t|Ráfaga|\t|Prioridad|\t\t|T Time|\t|W Time|\n";
    for (i=0; i<num; i++) {
        cout<<"\tP["<<PID[i]<<"]"<<"\t\t\t"<<AT[i]<<"\t\t\t\t"<<RT[i]<<"\t\t\t\t"<<PR[i]<<"\t\t\t"<<TT[i]<<"\t\t\t"<<WT[i]<<"\n";
    }

}

void sjf()
    {
        float AT[10], RT[10], TT[10], WT[10], ST[10], FT[10];
        int num,i, j;
        int PID[10];
        float temp, temp1;
        int temp2;
        
        cout << " Ingrese cantidad de procesos : ";
        cin>>num;
        for (i=0; i<num; i++) {
            cout<<"\n Tiempo de llegada";
            cout<<" P["<<i+1<<"] : ";
            cin>>AT[i];
            cout<<" Ráfaga ";
            cout<<" P["<<i+1<<"] : ";
            cin>>RT[i];
            PID[i]=i+1;
        }
        
        cout<<"\n\n|Proceso|\t|Tiempo llegada|\t|Ráfaga|\n";
        for (i=0; i<num; i++) {
            cout<<"\tP["<<i+1<<"]"<<"\t\t\t"<<AT[i]<<"\t\t\t\t"<<RT[i]<<"\n";
        }
        
        for(i=0;i<num;i++)
        {
            for(j=0;j<num;j++)
            {
                if(RT[i]<RT[j])
                {
                    temp2=PID[i];
                    PID[i]=PID[j];
                    PID[j]=temp2;
                
                    temp1=AT[i];
                    AT[i]=AT[j];
                    AT[j]=temp1;
                    
                    temp=RT[i];
                    RT[i]=RT[j];
                    RT[j]=temp;
                }
            }
        }
        
        for(i=0;i<num;i++){
            
            if(i==0)
            {
                ST[i]=AT[i];
                WT[i]=ST[i]-AT[i];
                FT[i]=ST[i]+RT[i];
                TT[i]=FT[i]-AT[i];
                
            }
            else
            {
                ST[i]=FT[i-1];
                WT[i]=ST[i]-AT[i];
                FT[i]=ST[i]+RT[i];
                TT[i]=FT[i]-AT[i];
            }
        }
        
        cout<<"\n \t\t\t ---- SJF ---- ";
        cout<<"\n\n|Proceso|\t|Tiempo llegada|\t|Ráfaga|\t|T Time|\t|W Time|\n";
        for (i=0; i<num; i++) {

            cout<<"\tP["<<PID[i]<<"]"<<"\t\t\t"<<AT[i]<<"\t\t\t\t"<<RT[i]<<"\t\t\t"<<TT[i]<<"\t\t\t"<<WT[i]<<"\n";
            
        }
    }

int main(){
    
    int n;
    cout<<"\n\t _______ Algoritmos Sistemas Operativos _______\n";
    cout<<"\n ******************************************************* \n";
    cout<<"\n Nombre: Vladimir Bustamante Muñoz \t rut: 19.005.873-6";
    cout<<"\n Profesor: Jorge Morris Arredondo \n ";
    cout<<"\n ******************************************************* \n";
    cout<<"\n Escoja Algoritmo : ";
    cout<<"\n 1) Round Robin \n";
    cout<<" 2) FCFS \n ";
    cout<<"3) Priority \n ";
    cout<<"4) SJF \n ";
    cout<<"\n Seleccione numero 1-4 : ";
    cin>>n;
    
    switch (n) {
        case 1:
            rr();
            break;
        case 2:
            fcfs();
            break;
        case 3:
            priority();
            break;
        case 4:
            sjf();
        default:
            break;
    }
    return 0;
}
