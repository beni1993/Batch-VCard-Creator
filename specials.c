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
#include"specials.h"
#ifndef  STDIO_H  
#include<stdio.h>
#endif
#ifndef  STRING_H
#include<string.h>
#endif

/* Umlautcheck */
int umlautinside(char *string){
   int i = 0;  
   while(1){
      if(string[i] == '\0'){
         return 0;  
         break;
      }
      if(!(string[i] >= 10 && string[i] <= 127))
         return 1;
      i++;
   }
}

void stringappend(char *text, char *apptext){
   int index1,index2;
   
   for(index1=0;text[index1]!='\0';index1++);
   
   for(index2=0;apptext[index2]!='\0';index2++,index1++)
      text[index1] = apptext[index2];
      
   text[index1] = '\0';
}

void quotetprintable(unsigned char *destination,unsigned char *source){
   int i;
   unsigned char c = ' ';
   unsigned char temp[4] = "";
   destination[0] = '\0';
   
   for(i=0;source[i] != '\0'; i++){
      sprintf(temp,"=%X",source[i]);
      stringappend(destination,temp);
   }
}

/* Identifies comments and blank lines */
int comment (char *string){
   int i;
   for (i = 0; string[i] == ' ' && i < 300; i++);

   switch(string[i]){
   case '#':
      return 1;
      break;
   case '/':
      return 1;
      break;
   case '<':
      return 1;
      break;
   case '*':
      return 1;
      break;
   case '\n':
      return 2;
      break;
   case '\0':
      return 2;
      break;
   default:
      return 0;
   }
   return 0;
}

void new_vcard (char *new, contact new_contact) {
   char line[300];
   char qp_firstname[150];
   char qp_lastname[150];
   strcpy (new, "BEGIN:VCARD\nVERSION:2.1\n");
   if(umlautinside (new_contact.firstname) || umlautinside (new_contact.lastname)) {    
      quotetprintable (qp_firstname, new_contact.firstname);
      quotetprintable (qp_lastname, new_contact.lastname);
      sprintf (line, "N;CHARSET=UTF-8;ENCODING=QUOTED-PRINTABLE:%s;%s;;;\n",
               qp_lastname, qp_firstname);
      stringappend (new, line);
      sprintf (line, "FN;CHARSET=UTF-8;ENCODING=QUOTED-PRINTABLE:%s=20%s\n",
               qp_firstname, qp_lastname);
      stringappend (new, line);
   }
   else {
      sprintf (line, "N:%s;%s;;;\n", new_contact.lastname,
               new_contact.firstname);
      stringappend (new, line);
      sprintf (line, "FN:%s %s\n", new_contact.firstname,
               new_contact.lastname);
      stringappend (new, line);
   }
   sprintf (line, "TEL;CELL:%s\n", new_contact.mobilenumber);
   stringappend (new, line);
   stringappend (new, "END:VCARD\n");
}

void print_helptext(){
   printf("Aufruf: %s [DATEI] [OPTIONEN]\n\n",PROGRAMMNAME);
   printf("Optionen:\n"
          "   -o <dateiname>  Legt den Namen der Ausgabedatei fest.\n"             
          "   -h   --help     Diese Hilfeinformationen anzeigen und beenden.\n"
          "   -v   --version  Versionsinformationen anzeigen und beenden.\n\n"
          "Beispielaufruf:\n"
          "   %s liste.txt -o vcard.vcf"
          "  \n",PROGRAMMNAME);
}

void print_versiontext(){
   printf("%s - Version: %s\n",PROGRAMMNAME,PROGRAMMVERSION);
   printf("Copyright © 2016 %s\n" ,PROGRAMMAUTOR);
   printf("zlib/libpng License <opensource.org/licenses/zlib-license.php>\n\n");
   printf("Geschrieben von " PROGRAMMAUTOR "\n");
}
