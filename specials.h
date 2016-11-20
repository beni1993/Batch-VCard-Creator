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
#define PROGRAMMNAME "bvcard-creator"
#define PROGRAMMVERSION "1.00"
#define PROGRAMMAUTOR "Benjamin Hedert"
enum{
   HELP_OPT,
   VERSION_OPT,
   OUTPUTFILE_OPT
};

typedef struct {
   char firstname[50];
   char lastname[50];
   char mobilenumber[30];
} contact;


/*     Functions             */
void print_helptext();
void print_versiontext();
int umlautinside(char *string);
void stringappend(char *text, char *apptext);
void quotetprintable(unsigned char *destination,unsigned char *source);
void new_vcard (char *new, contact new_contact);
int comment (char *string);
