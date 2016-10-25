/******************************************************************************!
 * \file     graphique.c
 * \author   Durand Kévin
 * \author   Soupramanian Arnold
 * \version  1.0
 * \date     23/10/16
 * \brief    Implémentation des fonctions pour les rendus graphiques
 * 
 * \details  Utilisation de la bibliothèque SDL pour gérer la partie graphique
 *           du projet et surement les événements utilisateurs
 * 
 ******************************************************************************/

#include "graphique.h"
#include "resolution.h"

Sudoku* initSudoku(){
    Sudoku* s = (Sudoku*)malloc(sizeof(Sudoku));
    s->enJeu    = TRUE;
    s->fenetre  = NULL;
    s->font     = NULL;
    s->rendu    = NULL;
    s->fdJeu    = NULL; 
    s->fdMenu   = NULL;
    s->fdTitre  = NULL;
    s->rectGrille =(SDL_Rect){0,0,0,0};
    s->rectTitre  =(SDL_Rect){0,0,0,0};
    return s;
}

Menu* initMenu(){
    Menu* m = (Menu*)malloc(sizeof(Menu));
    m->nb = 0;
    int i;
    for(i=0;i<NB_BOUTON_MAX;++i){
        m->fdBouton[i] = NULL;
        m->fdTextBouton[i] = NULL;
        m->rect[i] = (SDL_Rect){0,0,0,0};
    }
    return m;
}

Boolean initSDL(Sudoku* sudoku){
    //Initialisation de la SDL
    if(SDL_Init(SDL_INIT_EVERYTHING)<0){
        printf("Pb d'initialisation! SDL_Error: %s\n", SDL_GetError());
        return FALSE;
    }
    //Création de la fenetre
    sudoku->fenetre = SDL_CreateWindow("L3S5 Sudoku C", SDL_WINDOWPOS_CENTERED, 
                                          SDL_WINDOWPOS_CENTERED,
                                          ECRAN_LARGEUR, ECRAN_HAUTEUR,
                                          SDL_WINDOW_SHOWN);
    if(!sudoku->fenetre){
        printf("Pb de création de fenetre! SDL_Error: %s\n", SDL_GetError());
        return FALSE;
    }
    //Creation d'un rendu pour la fenetre
    sudoku->rendu = SDL_CreateRenderer(sudoku->fenetre, -1,
                                         SDL_RENDERER_ACCELERATED);
    if(!sudoku->rendu){
        printf("Renderer n'a pas pu etre cree! \n"
               "SDL Error: %s \n", SDL_GetError());
        return FALSE;
    }
    //Init la couleur du rendeur
    SDL_SetRenderDrawColor(sudoku->rendu,0xFF, 0xFF, 0xFF, 0xFF);
    
     //Initialize PNG loading 
    int imgFlags = IMG_INIT_JPG;
    if( !( IMG_Init(imgFlags) && imgFlags ) ) { 
        printf( "SDL_image could not initialize!\n"
                "SDL_image Error: %s\n", IMG_GetError() );
        return FALSE;
    }
    
    //Initialise le sdl_ttf pour le texte
    if(TTF_Init()<0){
        printf("SDL_TFF could not initialize!\n"
               "SDL_TTF Error: %s\n", TTF_GetError());
        return FALSE;
    }
    

    return TRUE;
}

SDL_Texture* chargeTexture(char* chemin, SDL_Renderer* rendu){
    SDL_Texture* finalTexture = NULL;
    
    //Charge l'image a partir du chemin
    SDL_Surface* chargeSurface = IMG_Load(chemin);
    if(!chargeSurface){
        printf("Impossible de charger l'image %s! \n"
        "SDL_image Error: %s\n",chemin,IMG_GetError());
    }
    // Converti la surface au format de l'écran
    finalTexture = SDL_CreateTextureFromSurface(rendu,chargeSurface);
    if(!finalTexture){
        printf("Impossible de creer la texture de %s! \n"
        "SDL_Error: %s\n",chemin,SDL_GetError());
    }
    //On libère l'anciene surface non optimisé
    SDL_FreeSurface(chargeSurface);
    return finalTexture;
}

SDL_Texture* chargeTexte(char* texte, SDL_Color cTxt, Sudoku* sudoku,
                         SDL_Rect* rText){
    // Chargement d'une surface texte
    SDL_Surface *txtSurface = TTF_RenderText_Solid(sudoku->font,texte,cTxt);
    if(!txtSurface){
        printf("Impossible de rendre une surface de texte !\n"
               "SDL_ttf Error: %s\n", TTF_GetError());
        return NULL;
    }
    
    // Creation texture depuis une surface
    SDL_Texture* txt = SDL_CreateTextureFromSurface(sudoku->rendu, txtSurface);
    if(!txt){
        printf("Impossible de crer une texture depuis le rendu texte !\n"
               "SDL_ttf Error: %s\n", SDL_GetError());
        return NULL;
    }
  
    // recupere les dimension de la surface
    if(rText!=NULL){
        rText->w = txtSurface->w;
        rText->h = txtSurface->h;
    }
       
    //Libere mémoire
    SDL_FreeSurface(txtSurface);
    return txt;
}

Boolean configureSudoku(Sudoku* sudoku){
   //Chargement de la police
    sudoku->font = TTF_OpenFont("font/hipster.ttf",48);
    if(!sudoku->font){
        printf("Fail lors du chargement de la police!\n"
                "SDL_ttf Error: %s\n", TTF_GetError());
        return FALSE;
    }
    // Chargement des images de fond
    sudoku->fdMenu=chargeTexture("img/fdMenu.jpg",sudoku->rendu);
    sudoku->fdJeu =chargeTexture("img/fdJeu.jpg", sudoku->rendu);
    if (!sudoku->fdMenu || !sudoku->fdJeu){
        printf("Echec lors du chargement de la texture image! \n");
        return FALSE;
    }    
   
    // Chargement du titre
    SDL_Color cTxt = {0,0,0}; //noir en rgb
    if(!(sudoku->fdTitre= chargeTexte("Sudoku", cTxt, sudoku,
                                     &sudoku->rectTitre))){
        printf("Fail pour rendre la texture text!\n");
        return FALSE;
    }
    sudoku->rectTitre.x = (ECRAN_LARGEUR/2) - (sudoku->rectTitre.w /2);
    sudoku->rectTitre.y = HAUTEUR_TITRE;

    return TRUE;
}

Boolean configMenu(Menu* menu, int nb, char** textBouton, SDL_Color cTxt,
                   Sudoku* sudoku){
    if(nb>NB_BOUTON_MAX){
        printf("Le nb de bouton est limite a %d !\n",NB_BOUTON_MAX);
        return FALSE;
    }
    // on va initialiser leurs positions et espaces avec leur rectangles
    // on les centre d'office au centre de la fenetre en dessous du titre
    int i; menu->nb = nb;
    for(i=0;i<menu->nb;++i){
        menu->rect[i] = (SDL_Rect){
            (ECRAN_LARGEUR/2) - (BOUTON_LARGEUR/2),
            (ECRAN_HAUTEUR/2) - ((BOUTON_HAUTEUR)*menu->nb)
                              + HAUTEUR_TITRE + i*(BOUTON_HAUTEUR+20),
            BOUTON_LARGEUR,
            BOUTON_HAUTEUR
        };
        menu->rectTxt[i]= (SDL_Rect){
            menu->rect[i].x + BOUTON_LARGEUR/4,
            menu->rect[i].y + BOUTON_HAUTEUR/4,
            menu->rect[i].w - BOUTON_LARGEUR/2,
            menu->rect[i].h - BOUTON_HAUTEUR/2     
        };
        
        
        // Charge la meme image de bouton pour tous
        menu->fdBouton[i] = chargeTexture("img/fdBouton.jpg",sudoku->rendu);
        if(menu->fdBouton[i]==NULL){
            printf("Echec lors de initMenu de la texture image! \n");
            return FALSE;
        }
        menu->fdTextBouton[i] = chargeTexte(textBouton[i],cTxt,sudoku,NULL);
        if(menu->fdTextBouton[i]==NULL){
            printf("Echec lors de initMenu de la texture texte! \n");
            return FALSE;
        }
    }
    return TRUE;
}

void dessinMenu(Menu* m, Sudoku* sudoku){
    int i;
    for(i=0;i<m->nb;++i){
        SDL_RenderCopy(sudoku->rendu,m->fdBouton[i],NULL,&m->rect[i]);
        SDL_RenderCopy(sudoku->rendu,m->fdTextBouton[i],NULL,&m->rectTxt[i]);
    }
    
}

Boolean recupEntree(SDL_Event *e, Position *p){
    // FILE des événements (interaction clavier/souris, joystick, etc..)
    // Boucle d'événement jusqu'à ce que la FILE soit vide
    while(SDL_PollEvent(e)){
        switch(e->type){
            case SDL_QUIT:
                return FALSE;
                break;
            case SDL_MOUSEBUTTONDOWN:
                switch(e->button.button){
                    case SDL_BUTTON_LEFT:
                        SDL_GetMouseState(&p->x,&p->y);
                        break;
                    default:
                        break;
                }
            default:
                break;
        }
    }
    return TRUE;
}

Boolean estDansRect(SDL_Rect* rect, Position* p){
    // Si les coordonnées vérifie ces conditions alors l'on est hors du rectangle
    if (p->x > rect->x+rect->w || p->x < rect->x 
        || p->y > rect->y+rect->h || p->y < rect->y)
        return FALSE;
    // Si oui retourne 1
    return TRUE;
}

void freeMenu(Menu* m){
    int i;
    for(i=0;i<m->nb;++i){
        SDL_DestroyTexture(m->fdBouton[i]);
        SDL_DestroyTexture(m->fdTextBouton[i]);
    }
    free(m);
}

void quitSDL(Sudoku* sudoku){
    SDL_DestroyTexture(sudoku->fdJeu);
    SDL_DestroyTexture(sudoku->fdMenu);
    SDL_DestroyTexture(sudoku->fdTitre);
    SDL_DestroyRenderer(sudoku->rendu);
    TTF_CloseFont(sudoku->font);
    SDL_DestroyWindow(sudoku->fenetre);
    
    // Quitte les sous-système SDL
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
    free(sudoku);
}