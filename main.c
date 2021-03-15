#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include <ctype.h>
#include <time.h>
#include <sys/types.h>
#include<dirent.h>



int main(){
FILE *file;
file = fopen("x.txt","r");
char ch = getc(file);
int chgo = 0;
char komut[10][50];
int go;
int make;
int o = 0;
int k = 0;
int l = 0;
int kontroler = 0;
int kontroller2 = 0;
int dogruluksayac  =0 ;
int kontrollerhata = 0;
int komutimlec = 0;
int geriimlec = 0;
int sayacimlec = 0;
int kontroller3 = 0;
int ikincigokontroller = 0;
int makeimlec = 0;
char dizin[30];
int makeimlecsayac = 0;

int sayac = 0;
int chkomut = 0;
char *komutcurrentDirectory ;
char komutarray[PATH_MAX-1];
komutcurrentDirectory = getcwd(komutarray,PATH_MAX-1);
char *ilkDirectory;
char arrayilk[PATH_MAX-1];
char * gocurrentDirectory ;
char goarray[PATH_MAX-1];
int gokomut = 0;
int ifkontrol2 = 1;
char *ifarrayadres;
char ifarray[PATH_MAX-1];
char *ifnotadres;
char ifnotarray[PATH_MAX-1];
int ifkontrol1 = 0;
int ifnotkontrol1 = 0;
int ifnotkontrol2 = 0;
char keywords[4][20];

strcpy(keywords[0],"go");
strcpy(keywords[1],"make");
strcpy(keywords[2],"if");
strcpy (keywords[3],"ifnot");



printf("%s\n","!!!!!!komutlarin duzgun calismasi icin if komutu haric sonuna noktali virgul konulmalidir !!!!!!!! ");
printf("%s\n","!!!!!!! Girilen ilk komutun basinda bosluk olmalidir!!!!!  ");
printf("%s\n", "!!!!  Program case sensitive dir !!!! ");
ilkDirectory = getcwd(arrayilk,PATH_MAX-1);

int ilkdirectorylen = strlen(ilkDirectory);
for(int k = 0 ; k<ilkdirectorylen;k++){
    if((ilkDirectory[k]==47)||(ilkDirectory[k]==92)){
        sayacimlec = sayacimlec+1;
    }
}
//Komutları file dan alma
while(!feof(file)){

    fscanf(file,"%s",&komut[o]);
    o++;

}



int parantezfarki = 1;
 int yerparantezilk = 0;
 int  yerparantezson= 0;

 int ifnotparantezfarki = 1;
 int yerifnotparantezilk = 0;
 int yerifnotparantezson = 0;



int yerparantezilk2 = 0;
int yerparantezson2 = 0;

int yerifnotparantezilk2 = 0;
int yerifnotparantezson2 = 0;




//komut içinde döngü yaratma
for(int m = 0; m<10; m++){
//komut belirleme
int komutkontrol = 0;
int gokomutsayac  =0;
int makekomutsayac =0;
int ifkomutsayac = 0;
int ifnotkomutsayac  =0;


int uzunluk = strlen(komut[m]);
int h = 0;
for(int n = 0 ; n<uzunluk ; n++){
    if(keywords[0][h] == komut[m][n]){
        gokomutsayac = gokomutsayac+1;
        h++;
    }
}

if(gokomutsayac == 2){
    komutkontrol = 1;
}

int p = 0;
for(int n = 0; n<uzunluk ;n++){
    if(keywords[1][p] == komut[m][n]){
        makekomutsayac = makekomutsayac+1;
        p++;
    }
}
if(makekomutsayac == 4){
    komutkontrol = 2;
}
int y = 0;
for(int n = 0; n<uzunluk;n++){
    if(keywords[2][y] == komut[m][n]){
            ifkomutsayac = ifkomutsayac+1;
            y++;

    }
}
if(ifkomutsayac == 2){
    komutkontrol = 3;
}
int x = 0;
for(int n = 0; n<uzunluk ; n++){
    if(keywords[3][x] ==komut[m][n]){
        ifnotkomutsayac = ifnotkomutsayac+1;
        x++;
    }
}
if(ifnotkomutsayac == 5){
    komutkontrol = 4;
}
//go komutu
if(komutkontrol == 1){

int a = 0;
 int  dogruluksayac = 0;
 int kontrollerhata = 0;
 int  komutimlec = 0;
 int  kontroller2 = 0;
 int  geriimlec = 0;
 int chgo = 0;
 int goarrayniilk = 0;

if(gokomut>0){

    gocurrentDirectory = getcwd(goarray,PATH_MAX-1);
        int goarrayboyut = strlen(goarray);
        for (int i = 0; i<ilkdirectorylen ; i++){

            if(goarray[i] == arrayilk[i]){
                goarrayniilk = goarrayniilk+1;
            }
            if((goarrayniilk==goarrayboyut)&&(goarrayniilk>1)){
                ikincigokontroller = 1;
                break;
            }

        }

    if(ikincigokontroller == 1){
        char eklearray[ilkdirectorylen-goarrayboyut+1];
        int h = 0;
        for(int g = goarrayboyut ; g<ilkdirectorylen;g++){
            eklearray[h] = arrayilk[g];
            h++;
        }
        eklearray[h] = '\0';
        int boyut = strlen(eklearray);
        char *tokengo = strtok(eklearray,"\\");
        while(tokengo!=NULL){


            chdir(tokengo);
            tokengo = strtok(NULL,"\\");
        }
        ikincigokontroller = 0;
    }


}

        for(int k = 0 ;k<uzunluk ; k++){
            if((komut[m][k+3]==ilkDirectory[k])||(komut[m][k+4] == ilkDirectory[k])){
                dogruluksayac = dogruluksayac+1;
            }
            if((dogruluksayac == uzunluk-5)||(dogruluksayac == uzunluk-6)||komut[m][k]==42){
                kontrollerhata = 1;
                break;
            }
        }
        if(kontrollerhata == 1){
            while(a<uzunluk){
                if((komut[m][a]==92||komut[m][a] == 47)){
                    komutimlec = komutimlec+1;
                    a++;
                }
                if(komut[m][a] == 42){
                    komutimlec = komutimlec+1;
                    kontroller2 = 1;
                    a++;
                }
                else{
                    a++;
                }
            }
            if(kontroller2==0){
                geriimlec = sayacimlec-komutimlec;
            }
            else{
                geriimlec = komutimlec;
            }


            for(int b = 1 ; b<geriimlec+1;b++){
                chgo = chdir("..");
            }


            gocurrentDirectory = getcwd(goarray,PATH_MAX-1);
            if(gocurrentDirectory != NULL){
                printf("My working directory is %s.\n",gocurrentDirectory);
            }


        }
                if(kontrollerhata == 0){
                printf("%s","Boyle bir dosya bulunamadi  ");
    }


            gokomut = gokomut+1;
            continue;
    }
//make komutu
    if(komutkontrol==2){
        int uzunluk = strlen(komut[m]);
        int komutkaraktersayi = strlen(komut[m]);

        for (int f = 0; f<komutkaraktersayi;f++){
            if((komut[m][f] == 47)||(komut[m][f]==92)){
                kontroller3 = 1;
                break;
            }
            else if((komut[m][f]!=47)||(komut[m][f] !=92)){
                kontroller3 = 0;


            }
        }
        if(kontroller3 == 0){
            for(int c = komutkaraktersayi ; c>=0;c--){
                if(komut[m][c] == 60){

                    makeimlec = c;
                    break;
                }
            }
            int d = makeimlec+1;
            int alinacakfile = komutkaraktersayi-3-d;
            while(komut[m][d]!=62){
                for(int e = 0; e<alinacakfile+1;e++){
                    dizin[e] = komut[m][d];
                    d = d+1;
                }
            }

            komutcurrentDirectory = getcwd(komutarray,PATH_MAX-1);
            int r = mkdir(dizin);
            if(r==1){
                printf("\nDizin olusturulamadý \n");

            }
            else{
                printf("\nDizin olusturuldu  \n");
            }

            if(komutcurrentDirectory !=NULL){
                printf("My working directory is %s.\n",komutcurrentDirectory);
            }

        }
        if(kontroller3 == 1){
                int komutlen = strlen(komut[m]);

                int yildizsayac = 0;



                char makearray[PATH_MAX] ;


               char str[komutlen-7];
               char str1[komutlen-7];
               int kucuktur = 0;
               int buyuktur = 0;
               for(int k = 0; k<komutlen;k++) {
                if(komut[m][k] == 60){
                    kucuktur = k;
                }
               }
               for (int n =0; n<komutlen;n++){
                if(komut[m][n] == 62){
                    buyuktur = n;
                }
               }

               int h = 0;
               for(int i = kucuktur+1;i<buyuktur;i++){
                str[h] = komut[m][i];
                h++;
               }
               str[h] = '\0';
               int strninlen = strlen(str);
               for (int q = 0; q<strninlen;q++){
                if(str[q] == 42){
                        yildizsayac = yildizsayac+1;

                }
               }
               for (int p = 1;p<yildizsayac+1;p++){
                chdir("..");
               }
               getcwd(makearray,PATH_MAX-1);
               for(int v = 0; v<strninlen;v++){
                if(str[v] == 42){
                    str[v] = str[v+1];
                }
               }
               int u = 0;
               for(int l = yildizsayac*2; l<strninlen;l++){
                    str1[u] = str[l];
                    u++;
               }


               str1[u] = '\0';
                int strninlen1 = strlen(str1);
               char *token = strtok(str1,"\\");
               while (token!=NULL){


                int arrayilklen = strlen(makearray);
                makearray[arrayilklen] = '\\';
                arrayilklen = arrayilklen+1;
                makearray[arrayilklen] = '\0';
                strcat(makearray,token);
                int arrayilklen2 = strlen(makearray);
                makearray[arrayilklen2] = '\0';
                opendir(token);
                int r = mkdir(makearray);

                token = strtok(NULL,"\\");

               }

        }
        continue;

    }//<*/*directory> gibi komutlar
    if(komut[m][0] == 60){
        int uzunluk = strlen(komut[m]);
        if(komut[m][1]!=42){
            printf("%s","Hatalı giriş");
            break;
        }
        else{
        for(int i = 0 ; i<50 ; i++){

        if(komut[m][i]==42)
            sayac++;
       }

       for(int j = 1 ; j<sayac+1;j++){
        chkomut = chdir("..");
       }


       komutcurrentDirectory = getcwd(komutarray,PATH_MAX-1);
       if(komutcurrentDirectory != NULL){
        printf("My working directory is %s.\n", komutcurrentDirectory);
       }

        }

continue;

    }
    //if komutu
    if(komutkontrol == 3){

        int uzunluk = strlen(komut[m]);
        int slashyer =0;

        ifarrayadres=getcwd(ifarray,PATH_MAX-1);
        int ifarraylen = strlen(ifarray);
        int ifdogruluksayac = 0;
        char ifarrayiki[uzunluk-4];

        int t = 0;
        for(int i = 3; i<uzunluk-1;i++){
            ifarrayiki[t] = komut[m][i];
            t++;
        }
        ifarrayiki[t] = '\0';
        int ifarrayikilen = strlen(ifarrayiki);



        for(int i = 0; i<ilkdirectorylen ; i++){
            if((arrayilk[i]==92)||(arrayilk[i]==47)){
                slashyer = i;
                break;
            }

        }


        for(int i = 0; i<uzunluk ; i++){
            if(komut[m][i] == 42){
                ifkontrol1 = 1;
                break;
            }
            if(komut[m][i] != 42){
                ifkontrol1 = 0;

            }
        }


        if(ifkontrol1 == 1){
           if(ifarraylen==slashyer+1){
                parantezfarki = 2;
                for(int k = 0; k<10 ; k++){
                    int len = strlen(komut[m]);
                    for (int n = 0; n<len ; n++){
                        if(komut[k][n] ==123){
                            yerparantezilk2 = k;
                        }

                    }
                    for(int n = 0; n<len ; n++){
                        if(komut[k][n]==125){
                            yerparantezson2 = k ;
                        }
                    }
                    if(yerparantezson2-yerparantezilk2>0){
                        parantezfarki = yerparantezson2-yerparantezilk2+1;
                    }
                }
           }

        }

        if(ifkontrol1 == 0){
            int h =0;
            for(int i = 0; i<ilkdirectorylen;i++) {
            if(arrayilk[i] == ifarrayiki[h]){
                ifdogruluksayac = ifdogruluksayac+1;
                h++;
            }
            if(ifdogruluksayac == ifarrayikilen){
              ifkontrol2 = 0;
              break;
            }

            }

            if(ifkontrol2 == 1){
                parantezfarki = 2;
                for(int k = 0; k<10;k++){
                int len = strlen(komut[m]);
                for(int n = 0; n<len;n++){
                    if(komut[k][n]==123){
                        yerparantezilk  = k;


                    }


                }
                for(int n = 0; n<len;n++){
                    if(komut[k][n] == 125){
                        yerparantezson = k;

                    }

                }



                if(yerparantezson-yerparantezilk>0){
                parantezfarki = yerparantezson-yerparantezilk+1;
               }

                }
            }

        }

        for(int i = 0; i<parantezfarki-1;i++){
                m = m+1;

                }

            continue;

    }
//ifnot komutu
    if(komutkontrol==4){


       int uzunluk = strlen(komut[m]);
       int ifnotslashyer = 0;
       ifnotadres = getcwd(ifnotarray,PATH_MAX-1);
       int ifnotarraylen = strlen(ifnotarray);
       int ifnotdogruluksayac = 0;
       char ifnotarrayiki[uzunluk-7];
       int k = 0;
       for(int i = 5 ; i<uzunluk ; i++){
        ifnotarrayiki[k] = komut[m][i];
        k++;
       }

       ifnotarrayiki[k] = '\0';
       int ifnotarryikilen = strlen(ifnotarrayiki);

       for(int i = 0; i<ilkdirectorylen;i++){
        if((arrayilk[i]==92)||(arrayilk[i]==47)){
            ifnotslashyer = i;
            break;
        }
       }
       for(int i = 0; i<uzunluk; i++){
        if(komut[m][i] == 42){
            ifnotkontrol1 = 1;
            break;
        }
        if(komut[m][i]!=42){
            ifnotkontrol1 = 0;
        }
       }
       if(ifnotkontrol1 == 1){
        if(ifnotarraylen != ifnotslashyer+1){
            ifnotparantezfarki = 2;
            for(int k  =0; k<10;k++){
                int len = strlen(komut[m]);
                for(int n = 0; n<len ; n++){
                    if(komut[k][n] ==123){
                        yerifnotparantezilk2 = k;
                    }
                }
                for(int n = 0; n<len ; n++){
                    if(komut[k][n] ==125){
                        yerifnotparantezson2 = k;
                    }
                }
                if(yerifnotparantezson2-yerifnotparantezilk2>0){
                    ifnotparantezfarki = yerifnotparantezson2-yerifnotparantezilk2+1;
                }
            }

        }
       }

       if(ifnotkontrol1 == 0){
            int h =0;
            for ( int i = 0; i<ilkdirectorylen;i++){
                if(arrayilk[i] == ifnotarrayiki[h]){
                    ifnotdogruluksayac = ifnotdogruluksayac+1;
                    h++;
                }
                if(ifnotdogruluksayac == ifnotarryikilen){
                    ifnotkontrol2 = 0;
                    break;
                }
            }

            if(ifnotkontrol2 == 0){
                ifnotparantezfarki = 2;
                for(int k = 0; k<10;k++){
                    int len = strlen(komut[m]);
                    for(int n = 0 ; n<len ; n++){
                        if(komut[k][n] == 123){
                            yerifnotparantezilk = k;
                        }
                    }
                    for(int n = 0 ; n<len ; n++){
                        if(komut[k][n] == 125){
                            yerifnotparantezson = k;
                        }
                    }
                    if(yerifnotparantezson-yerifnotparantezilk>0){
                        ifnotparantezfarki = yerifnotparantezson-yerifnotparantezilk+1;
                    }
                }
            }
       }
       for(int i = 0 ; i<ifnotparantezfarki-1 ;i++){
        m = m+1;
       }

        continue;
    }

    }

return 0;


}
