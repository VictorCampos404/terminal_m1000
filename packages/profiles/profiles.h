#ifndef PROFILES_H
#define PROFILES_H

static char *allProfilePath;
static char *profilePath;
static int nProfiles;

void initProfiles();
void criarPerfil(char**);
void escolherPerfil(char**);
char** getAllProfiles();

#endif
