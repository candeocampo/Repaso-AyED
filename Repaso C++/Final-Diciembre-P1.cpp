#include<iostream>
#include<stdio.h>
using namespace std;


struct tInfo{
    int codP;
    int stock;
    char tipo;
};

struct tPan{
    int codP;
    int stock;
};

struct Nodo{
    tInfo info;
    Nodo* sgte;
};

int main(){

    FILE* agos=fopen("BurgerFastAgosto.dat","rb");
    FILE* sept=fopen("BurgerFastSeptiembre.dat","rb");
    FILE* nuevo=fopen("BurgerFast.dat","wb");

    //PARTE B
    FILE* pan=fopen("Pan.dat","wb");
    tPan rauxC;

    //PARTE A
    //Consolidar los dos archivos de BurgerAgosto y BurgerSeptiembre
    tInfo rauxA;
    tInfo rauxB;
    fread(&rauxA,sizeof(struct tInfo),1,agos);
    fread(&rauxB,sizeof(struct tInfo),1,sept);
    while((!feof(agos)) && (!feof(sept))){
        if(rauxA.codP<rauxB.codP){
            if(rauxA.tipo=='P'){
                rauxC.codP=rauxA.codP;
                rauxC.stock=rauxA.stock;
                fwrite(&rauxC,sizeof(struct tInfo),1,pan); //lo escribimos en el archivo de panes.
            }
            fwrite(&rauxA,sizeof(struct tInfo),1,nuevo);
            fread(&rauxA,sizeof(struct tInfo),1,agos);
        }
        else{
            if(rauxB.tipo=='P'){
                rauxC.codP=rauxB.codP;
                rauxC.stock=rauxB.stock;
                fwrite(&rauxC,sizeof(struct tInfo),1,pan); //lo escribimos en el archivo de panes.
            }
            fwrite(&rauxB,sizeof(struct tInfo),1,nuevo);
            fread(&rauxB,sizeof(struct tInfo),1,sept);
        }
    }
    while(!feof(agos)){
        if(rauxA.tipo=='P'){
            rauxC.codP=rauxA.codP;
            rauxC.stock=rauxA.stock;
            fwrite(&rauxC,sizeof(struct tInfo),1,pan); //lo escribimos en el archivo de panes.
        }
        fwrite(&rauxA,sizeof(struct tInfo),1,nuevo);
        fread(&rauxA,sizeof(struct tInfo),1,agos);
    }
    while(!feof(sept)){
        if(rauxB.tipo=='P'){
            rauxC.codP=rauxB.codP;
            rauxC.stock=rauxB.stock;
            fwrite(&rauxC,sizeof(struct tInfo),1,pan); //lo escribimos en el archivo de panes.
        }
        fwrite(&rauxB,sizeof(struct tInfo),1,nuevo);
        fread(&rauxB,sizeof(struct tInfo),1,sept);
    }

    fclose(agos);
    fclose(sept);
    fclose(nuevo);



    return 0;
}
