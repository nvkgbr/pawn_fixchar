/*
Készítő:
    rolux  
 
Ékezetes karakterek javítása textdrawokban , gametextekben és menükben.
 
*/

#if defined r_fixchar_included
	#endinput
#endif
#define r_fixchar_included
#pragma library r_fixchar

stock ConvertEncoding(string[])
{
	new original[50] = {192,193,194,196,198,199,200,201,202,203,204,205,206,207,210,211,212,214,217,218,219,220,223,224,225,226,228,230,231,232,233,234,235,236,237,238,239,242,243,244,246,249,250,251,252,209,241,191,161,176};
	new fixed[50] = {128,129,130,131,132,133,134,135,136,137,138,139,140,141,142,143,144,145,146,147,148,149,150,151,152,153,154,155,156,157,158,159,160,161,162,163,164,165,166,167,168,169,170,171,172,173,174,175,94,124};
	for (new i; i < strlen(string); i++) {
		for(new j;j < 50;j++) {
			if(string[i] == original[j]) {
				string[i] = fixed[j];
				break;
			}
		}
	}
}

stock Text:r_fixchar_TextDrawCreate(Float:x, Float:y, text[]){	
	ConvertEncoding(text);
	return TextDrawCreate(x,y,text);
}

stock PlayerText:r_fixchar_CreatePlayerTextDraw(playerid, Float:x, Float:y, text[]){
	ConvertEncoding(text);
	return CreatePlayerTextDraw(playerid, x, y, text);
}
	
stock r_fixchar_GameTextForPlayer(playerid,text[],time,style){
    ConvertEncoding(text);
	return GameTextForPlayer(playerid,text,time,style);
}

stock r_fixchar_GameTextForAll(text[],time,style){
    ConvertEncoding(text);
	return GameTextForAll(text,time,style);
}

stock Menu:r_fixchar_CreateMenu(title[], columns, Float:x, Float:y, Float:col1width, Float:col2width = 0.0){
	ConvertEncoding(title);
	return CreateMenu(title,columns,x,y,col1width,col2width);
}

stock r_fixchar_SetMenuColumnHeader(Menu:menuid, column, columnheader[]){
    ConvertEncoding(columnheader);
	return SetMenuColumnHeader(menuid, column, columnheader);
}

stock r_fixchar_AddMenuItem(Menu:menuid, column, menutext[]){
    ConvertEncoding(menutext);
	return AddMenuItem(menuid, column, menutext);
}

stock r_fixchar_TextDrawSetString(Text:text, string[]){
    ConvertEncoding(string);
	return TextDrawSetString(text,string);
}

stock r_fixchar_PlayerTextDrawSet(playerid, PlayerText:text, string[]){
	ConvertEncoding(string);
	return PlayerTextDrawSetString(playerid,text,string);
}
//Hookok( 9db ):
/*=============================================================================*/	
#if defined _ALS_TextDrawCreate
    #undef TextDrawCreate
#else
    #define _ALS_TextDrawCreate
#endif
#define TextDrawCreate r_fixchar_TextDrawCreate
/*=============================================================================*/	
#if defined _ALS_CreatePlayerTextDraw
	#undef CreatePlayerTextDraw
#else
	#define _ALS_CreatePlayerTextDraw
#endif
#define CreatePlayerTextDraw r_fixchar_CreatePlayerTextDraw
/*=============================================================================*/	
#if defined _ALS_GameTextForPlayer
    #undef GameTextForPlayer
#else
    #define _ALS_GameTextForPlayer
#endif
#define GameTextForPlayer r_fixchar_GameTextForPlayer
/*=============================================================================*/	
#if defined _ALS_GameTextForAll
    #undef GameTextForAll
#else
    #define _ALS_GameTextForAll
#endif
#define GameTextForAll r_fixchar_GameTextForAll
/*=============================================================================*/	
#if defined _ALS_CreateMenu
    #undef CreateMenu
#else
    #define _ALS_CreateMenu
#endif
#define CreateMenu r_fixchar_CreateMenu
/*=============================================================================*/	
#if defined _ALS_SetMenuColumnHeader
    #undef SetMenuColumnHeader
#else
    #define _ALS_SetMenuColumnHeader
#endif
#define SetMenuColumnHeader r_fixchar_SetMenuColumnHeader
/*=============================================================================*/	
#if defined _ALS_AddMenuItem
    #undef AddMenuItem
#else
    #define _ALS_AddMenuItem
#endif
#define AddMenuItem r_fixchar_AddMenuItem
/*=============================================================================*/	
#if defined _ALS_TextDrawSetString
    #undef TextDrawSetString
#else
    #define _ALS_TextDrawSetString
#endif
#define TextDrawSetString r_fixchar_TextDrawSetString	
/*=============================================================================*/		
#if defined _ALS_PlayerTextDrawSetString
    #undef PlayerTextDrawSetString
#else
	#define _ALS_PlayerTextDrawSetString
#endif
#define PlayerTextDrawSetString r_fixchar_PlayerTextDrawSet
/*=============================================================================*/	
