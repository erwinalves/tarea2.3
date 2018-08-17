#include <iostream>
#include <fstream>

using namespace std;

void limpiarLinea(string linea, string& aux){
    aux="";
    for(int i=0;i<linea.length();i++){
        if(linea[i]==','){
            i++;
            for(int j=i;j<linea.length();j++){
                if(linea[j]==','){
                    j=linea.length();
                    i=linea.length();
                }
                else{
                    aux=aux+linea[j];
                }
            }
        }
    }
}
/*
void agregarCarrera(string carreras[], string aux){
    int comp=0,i=0;
    if(carreras[0].length()==0){
        while(i<carreras.length()){
            if(carreras[i]==aux){
                i=carreras.length();
            }
            else if(i==carreras.length()-1){
                carreras[i]=aux;
            }
            else{
                i++;
            }
        }
    }
    else{
        carreras[0]=aux;
    }
}
*/
int main(){
    string linea="",aux;
    int cont=0;
    string contador[13786][2];
    ifstream fs("utem.csv", ifstream::in);//abrir fichero
    while(fs.good()){//ciclo hasta llegar al final
		getline(fs,linea);
		limpiarLinea(linea,aux);
		cout<<"linea: "<<aux<<"contador: "<<cont<<endl;
		cont++;
    }
    fs.close();
}
