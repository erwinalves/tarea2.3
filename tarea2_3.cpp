#include <iostream>
#include <fstream>
#include "mpi.h"

using namespace std;

struct alumno{
	string rut;
	string carrera;
	int ano;
};

int main(int argc, char* argv[]){
	int rank,procesadores,contador=0;
	MPI_Init(&argc, &argv);
	
	MPI_Comm_size(MPI_COMM_WORLD, &procesadores);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	int contadorxproc [procesadores];
	string linea;
	alumno todos[13787];

	for(int j=0;j<procesadores;j++) contadorxproc[j]=0;
    ifstream fs("utem.csv", ifstream::in);//abrir fichero
	while(fs.good()){//ciclo hasta llegar al final
		getline(fs,linea);
	    for(int i=0;i<procesadores;i++){
		    if(fs.get()=='\n'){//Busca cuando hay un salto de linea
		    	contador++;
		    	contadorxproc[i]++;
		        MPI_Send(&contador, 1, MPI_INT, i, 0, MPI_COMM_WORLD);
		        
		        MPI_Recv(&contador, 1, MPI_INT, i, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
	        }
	    }
	}    
	fs.close();
    cout<<"El archivo tiene = "<<contador-1<<endl;// resto 1 porque esta contando la primera linea (titulo de los datos)
    for(int k=0;k<procesadores;k++) cout<<"procesador "<< k <<": "<< contadorxproc[k]<<endl;
    MPI_Finalize();
}
