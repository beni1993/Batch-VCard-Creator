/*
Copyright (c) 2016 Benjamin Hedert

This software is provided 'as-is', without any express or implied warranty.
In no event will the authors be held liable for any damages arising from
the use of this software.

Permission is granted to anyone to use this software for any purpose, 
including commercial applications, and to alter it and redistribute it freely,
subject to the following restrictions:

    1. The origin of this software must not be misrepresented; you must not
       claim that you wrote the original software. If you use this software
       in a product, an acknowledgment in the product documentation would be
       appreciated but is not required.

    2. Altered source versions must be plainly marked as such, and must not
       be misrepresented as being the original software.

    3. This notice may not be removed or altered from any source distribution.
*/
#include<stdio.h>
#include<string.h>
#include"specials.h"
#define PARAMETER(x,y) if(strcmp((x),argv[i])==0) option=y

int main(int argc,char **argv){
   FILE *txtfile;
   FILE *vcffile;
   int option=-1,i;
   int inputfiles = 0;
   char outputfile[80];
   char inputfile[80];
   char fullvcard[400] = "";
   char newvc[400];
   char buffer[300];
   contact new_contact;
   strcpy(outputfile,"a.vcf");
   for(i=1;i<argc;i++){
      option = -1;
      
      PARAMETER("--help",HELP_OPT);      
      PARAMETER("-h",HELP_OPT);
      PARAMETER("--version",VERSION_OPT);
      PARAMETER("-v",VERSION_OPT);
      PARAMETER("-o",OUTPUTFILE_OPT);      

      switch(option){
         case HELP_OPT:
            print_helptext();
            return 0;
            break;
         case VERSION_OPT:
            print_versiontext();
            return 0; 
            break;
         case OUTPUTFILE_OPT:
            strncpy(outputfile,argv[++i],80);
            break;
         default:
            inputfiles++;
            if(inputfiles >= 2){
               printf("Nur eine Quelldatei möglich!\n");
               return 1;
            }
            strncpy(inputfile,argv[i],80);
      }  
   }
   
   if(inputfiles == 0){
      printf("Bitte geben sie eine Quelldatei an.\n");
      return 1;
   }
   
   txtfile = fopen (inputfile, "rt");
   vcffile = fopen (outputfile, "wt");

   if(vcffile == NULL || txtfile == NULL){
      perror("Dateien konnten nicht geöffnet werden!");
      return 1;
   }
   while (!feof(txtfile)) {
      fgets (buffer, 300, txtfile);
      if(!comment(buffer)) {
         sscanf(buffer, "%s %s %s", new_contact.firstname,
                 new_contact.lastname, new_contact.mobilenumber);
         new_vcard(newvc, new_contact);
         fprintf(vcffile, "%s", newvc);
      }
      buffer[0] = '\0';
   }
   fclose (txtfile);
   fclose (vcffile);

   return 0;
}
