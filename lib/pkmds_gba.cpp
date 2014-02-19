#ifdef PKMDS_CMAKE_USED
#include <pkmds/pkmds_gba.h>
#else
#include "../../PKMDS/include/pkmds/pkmds_gba.h"
#endif

int blocksizes[] = {
	3884, // Trainer info
	3968, // Team / items
	3968, // Unknown
	3968, // Unknown
	3848, // Rival info
	3968, // PC buffer A
	3968, // PC buffer B
	3968, // PC buffer C
	3968, // PC buffer D
	3968, // PC buffer E
	3968, // PC buffer F
	3968, // PC buffer G
	3968, // PC buffer H
	2000, // PC buffer I
};
int blocklocations[] = {
	0,     // Trainer info
	3884,  // Team / items
	7852,  // Unknown
	11820, // Unknown
	15788, // Rival info
	19636, // PC buffer A
	23604, // PC buffer B
	27572, // PC buffer C
	31540, // PC buffer D
	35508, // PC buffer E
	39476, // PC buffer F
	43444, // PC buffer G
	47412, // PC buffer H
	51380, // PC buffer I
};

void read(const char* file_name, gbasavefilepacked *data)
{
	std::ifstream *in = new std::ifstream(file_name,std::ios::binary);
	in->read(reinterpret_cast<char*>(data), sizeof(gbasavefilepacked));
	in->close();
	delete in;
	in = 0;
}
void read(const char* file_name, pokemon_gen3 *data)
{
	std::ifstream *in = new std::ifstream(file_name,std::ios::binary);
	in->read(reinterpret_cast<char*>(data), sizeof(pokemon_gen3));
	in->close();
	delete in;
	in = 0;
}

void buildgbasave(gbasavefilepacked * savin, gbasavefile * savout)
{
	int icount = 0;
	gbasaveblockpacked * block = new gbasaveblockpacked();
	byte * rawdata = reinterpret_cast<byte*>(savout);
	int cursave = 0;
	for(int i = 0; i < 16; i++)
	{
		block = reinterpret_cast<gbasaveblockpacked*>(&(savin->savea.blocks[i]));
		if(block->footer.validation == 0x08012025)
		{
			if(block->footer.saveindex > cursave)
			{
				cursave = block->footer.saveindex;
			}
		}
	}
	for(int i = 0; i < 16; i++)
	{
		block = reinterpret_cast<gbasaveblockpacked*>(&(savin->saveb.blocks[i]));
		if(block->footer.validation == 0x08012025)
		{
			if(block->footer.saveindex > cursave)
			{
				cursave = block->footer.saveindex;
			}
		}
	}
	for(int i = 0; i < 16; i++)
	{
		block = reinterpret_cast<gbasaveblockpacked*>(&(savin->savea.blocks[i]));
		if(block->footer.validation == 0x08012025)
		{
			if(block->footer.saveindex == cursave)
			{
				memcpy(&(rawdata[blocklocations[block->footer.sectionid]]),&(block->data), blocksizes[block->footer.sectionid]);
				icount++;
			}
		}
	}
	icount = 0;
	for(int i = 0; i < 16; i++)
	{
		block = reinterpret_cast<gbasaveblockpacked*>(&(savin->saveb.blocks[i]));
		if(block->footer.validation == 0x08012025)
		{
			if(block->footer.saveindex == cursave)
			{
				memcpy(&(rawdata[blocklocations[block->footer.sectionid]]),&(block->data), blocksizes[block->footer.sectionid]);
				icount++;
			}
		}
	}
	icount = 0;
}


//void sortsavefile(gbasavefile * sav)
//{
//	sortsaveblocks(&(sav->savefilea));
//	sortsaveblocks(&(sav->savefileb));
//}
//void sortsaveblocks(gbasavehalf * savehalf)
//{
//	sortblocks(savehalf->blocks);
//}
//bool compareblocks(gbasaveblock a, gbasaveblock b)
//{
//	return a.footer.sectionid < b.footer.sectionid;
//}
//void sortblocks(std::array<gbasaveblock,14> & theblocks)
//{
//	std::sort(theblocks.begin(),theblocks.end(),compareblocks);
//}
void decryptgbapkm(pokemon_gen3 * pkm)
{
	uint32 * TID = reinterpret_cast<uint32*>(&(pkm->tid));
	uint32 key = ((*TID)  ^ pkm->pid);
	uint32 * pkmpnt = new uint32;
	pkmpnt = reinterpret_cast<uint32*>(&(pkm->data));
	for(int i = 0; i < 12; i++)
	{
		pkmpnt[i] = (pkmpnt[i] ^ key);
	}
}
const byte t_shuffle[24][4] = {
	{0,1,2,3}, {0,1,3,2}, {0,2,1,3}, {0,2,3,1},
	{0,3,1,2}, {0,3,2,1}, {1,0,2,3}, {1,0,3,2},
	{1,2,0,3}, {1,2,3,0}, {1,3,0,2}, {1,3,2,0},
	{2,0,1,3}, {2,0,3,1}, {2,1,0,3}, {2,1,3,0},
	{2,3,0,1}, {2,3,1,0}, {3,0,1,2}, {3,0,2,1},
	{3,1,0,2}, {3,1,2,0}, {3,2,0,1}, {3,2,1,0}
};
void shufflegbapkm(pokemon_gen3 * pkm, bool un)
{
	byte * pkmpnt = new byte();
	pkmpnt = reinterpret_cast<byte*>(&(pkm->data));
	byte temp[48];
	//byte mode = (((((uint32*) pkmpnt)[0] >> 0xD) & 0x1F) % 24);
	byte mode = pkm->pid % 24;
	if (un) {
		memcpy(&(temp[t_shuffle[mode][0] * 12]), &pkmpnt[0 * 12], 12);
		memcpy(&(temp[t_shuffle[mode][1] * 12]), &pkmpnt[1 * 12], 12);
		memcpy(&(temp[t_shuffle[mode][2] * 12]), &pkmpnt[2 * 12], 12);
		memcpy(&(temp[t_shuffle[mode][3] * 12]), &pkmpnt[3 * 12], 12);
	} else {
		memcpy(&(temp[0 * 12]), &pkmpnt[t_shuffle[mode][0] * 12], 12);
		memcpy(&(temp[1 * 12]), &pkmpnt[t_shuffle[mode][1] * 12], 12);
		memcpy(&(temp[2 * 12]), &pkmpnt[t_shuffle[mode][2] * 12], 12);
		memcpy(&(temp[3 * 12]), &pkmpnt[t_shuffle[mode][3] * 12], 12);
	}
	memcpy(pkmpnt, &temp, 48);
}

/*

void shuffle(pokemon_obj * pkm, bool un)
{
byte * raw = reinterpret_cast<byte*>(pkm);
byte temp[128];
byte mode = (((((uint32*) raw)[0] >> 0xD) & 0x1F) % 24);

if (un)
{
memcpy(&(temp[t_shuffle[mode][0] * 32]), &raw[8 + 0 * 32], 32);
memcpy(&(temp[t_shuffle[mode][1] * 32]), &raw[8 + 1 * 32], 32);
memcpy(&(temp[t_shuffle[mode][2] * 32]), &raw[8 + 2 * 32], 32);
memcpy(&(temp[t_shuffle[mode][3] * 32]), &raw[8 + 3 * 32], 32);
}
else
{
memcpy(&(temp[0 * 32]), &raw[8 + t_shuffle[mode][0] * 32], 32);
memcpy(&(temp[1 * 32]), &raw[8 + t_shuffle[mode][1] * 32], 32);
memcpy(&(temp[2 * 32]), &raw[8 + t_shuffle[mode][2] * 32], 32);
memcpy(&(temp[3 * 32]), &raw[8 + t_shuffle[mode][3] * 32], 32);
}
memcpy(&raw[8], &temp, 128);
}


*/

void calcchecksum(pokemon_gen3 * pkm)
{
	uint32 sum = 0;
	uint16 * word = new uint16();
	word = reinterpret_cast<uint16*>(&(pkm->data));
	for(int i = 0; i < 24; i++)
	{
		sum += word[i];
	}
	pkm->checksum = sum;
}
int gbatods[386][2] = {
	{1,1},
	{2,2},
	{3,3},
	{4,4},
	{5,5},
	{6,6},
	{7,7},
	{8,8},
	{9,9},
	{10,10},
	{11,11},
	{12,12},
	{13,13},
	{14,14},
	{15,15},
	{16,16},
	{17,17},
	{18,18},
	{19,19},
	{20,20},
	{21,21},
	{22,22},
	{23,23},
	{24,24},
	{25,25},
	{26,26},
	{27,27},
	{28,28},
	{29,29},
	{30,30},
	{31,31},
	{32,32},
	{33,33},
	{34,34},
	{35,35},
	{36,36},
	{37,37},
	{38,38},
	{39,39},
	{40,40},
	{41,41},
	{42,42},
	{43,43},
	{44,44},
	{45,45},
	{46,46},
	{47,47},
	{48,48},
	{49,49},
	{50,50},
	{51,51},
	{52,52},
	{53,53},
	{54,54},
	{55,55},
	{56,56},
	{57,57},
	{58,58},
	{59,59},
	{60,60},
	{61,61},
	{62,62},
	{63,63},
	{64,64},
	{65,65},
	{66,66},
	{67,67},
	{68,68},
	{69,69},
	{70,70},
	{71,71},
	{72,72},
	{73,73},
	{74,74},
	{75,75},
	{76,76},
	{77,77},
	{78,78},
	{79,79},
	{80,80},
	{81,81},
	{82,82},
	{83,83},
	{84,84},
	{85,85},
	{86,86},
	{87,87},
	{88,88},
	{89,89},
	{90,90},
	{91,91},
	{92,92},
	{93,93},
	{94,94},
	{95,95},
	{96,96},
	{97,97},
	{98,98},
	{99,99},
	{100,100},
	{101,101},
	{102,102},
	{103,103},
	{104,104},
	{105,105},
	{106,106},
	{107,107},
	{108,108},
	{109,109},
	{110,110},
	{111,111},
	{112,112},
	{113,113},
	{114,114},
	{115,115},
	{116,116},
	{117,117},
	{118,118},
	{119,119},
	{120,120},
	{121,121},
	{122,122},
	{123,123},
	{124,124},
	{125,125},
	{126,126},
	{127,127},
	{128,128},
	{129,129},
	{130,130},
	{131,131},
	{132,132},
	{133,133},
	{134,134},
	{135,135},
	{136,136},
	{137,137},
	{138,138},
	{139,139},
	{140,140},
	{141,141},
	{142,142},
	{143,143},
	{144,144},
	{145,145},
	{146,146},
	{147,147},
	{148,148},
	{149,149},
	{150,150},
	{151,151},
	{152,152},
	{153,153},
	{154,154},
	{155,155},
	{156,156},
	{157,157},
	{158,158},
	{159,159},
	{160,160},
	{161,161},
	{162,162},
	{163,163},
	{164,164},
	{165,165},
	{166,166},
	{167,167},
	{168,168},
	{169,169},
	{170,170},
	{171,171},
	{172,172},
	{173,173},
	{174,174},
	{175,175},
	{176,176},
	{177,177},
	{178,178},
	{179,179},
	{180,180},
	{181,181},
	{182,182},
	{183,183},
	{184,184},
	{185,185},
	{186,186},
	{187,187},
	{188,188},
	{189,189},
	{190,190},
	{191,191},
	{192,192},
	{193,193},
	{194,194},
	{195,195},
	{196,196},
	{197,197},
	{198,198},
	{199,199},
	{200,200},
	{201,201},
	{202,202},
	{203,203},
	{204,204},
	{205,205},
	{206,206},
	{207,207},
	{208,208},
	{209,209},
	{210,210},
	{211,211},
	{212,212},
	{213,213},
	{214,214},
	{215,215},
	{216,216},
	{217,217},
	{218,218},
	{219,219},
	{220,220},
	{221,221},
	{222,222},
	{223,223},
	{224,224},
	{225,225},
	{226,226},
	{227,227},
	{228,228},
	{229,229},
	{230,230},
	{231,231},
	{232,232},
	{233,233},
	{234,234},
	{235,235},
	{236,236},
	{237,237},
	{238,238},
	{239,239},
	{240,240},
	{241,241},
	{242,242},
	{243,243},
	{244,244},
	{245,245},
	{246,246},
	{247,247},
	{248,248},
	{249,249},
	{250,250},
	{251,251},
	{277,252},
	{278,253},
	{279,254},
	{280,255},
	{281,256},
	{282,257},
	{283,258},
	{284,259},
	{285,260},
	{286,261},
	{287,262},
	{288,263},
	{289,264},
	{290,265},
	{291,266},
	{292,267},
	{293,268},
	{294,269},
	{295,270},
	{296,271},
	{297,272},
	{298,273},
	{299,274},
	{300,275},
	{304,276},
	{305,277},
	{309,278},
	{310,279},
	{392,280},
	{393,281},
	{394,282},
	{311,283},
	{312,284},
	{306,285},
	{307,286},
	{364,287},
	{365,288},
	{366,289},
	{301,290},
	{302,291},
	{303,292},
	{370,293},
	{371,294},
	{372,295},
	{335,296},
	{336,297},
	{350,298},
	{320,299},
	{315,300},
	{316,301},
	{322,302},
	{355,303},
	{382,304},
	{383,305},
	{384,306},
	{356,307},
	{357,308},
	{337,309},
	{338,310},
	{353,311},
	{354,312},
	{386,313},
	{387,314},
	{363,315},
	{367,316},
	{368,317},
	{330,318},
	{331,319},
	{313,320},
	{314,321},
	{339,322},
	{340,323},
	{321,324},
	{351,325},
	{352,326},
	{308,327},
	{332,328},
	{333,329},
	{334,330},
	{344,331},
	{345,332},
	{358,333},
	{359,334},
	{380,335},
	{379,336},
	{348,337},
	{349,338},
	{323,339},
	{324,340},
	{326,341},
	{327,342},
	{318,343},
	{319,344},
	{388,345},
	{389,346},
	{390,347},
	{391,348},
	{328,349},
	{329,350},
	{385,351},
	{317,352},
	{377,353},
	{378,354},
	{361,355},
	{362,356},
	{369,357},
	{411,358},
	{376,359},
	{360,360},
	{346,361},
	{347,362},
	{341,363},
	{342,364},
	{343,365},
	{373,366},
	{374,367},
	{375,368},
	{381,369},
	{325,370},
	{395,371},
	{396,372},
	{397,373},
	{398,374},
	{399,375},
	{400,376},
	{401,377},
	{402,378},
	{403,379},
	{407,380},
	{408,381},
	{404,382},
	{405,383},
	{406,384},
	{409,385},
	{410,386}
};
int convertgbaspecies(GBASpecies::gbaspecies in)
{
	for(int i = 0; i < 386; i++)
	{
		if(int(in) == gbatods[i][0])
		{
			return gbatods[i][1];
		}
	}
	return 0;
}
int dstogba[386][2] = {
	{1,1},
	{2,2},
	{3,3},
	{4,4},
	{5,5},
	{6,6},
	{7,7},
	{8,8},
	{9,9},
	{10,10},
	{11,11},
	{12,12},
	{13,13},
	{14,14},
	{15,15},
	{16,16},
	{17,17},
	{18,18},
	{19,19},
	{20,20},
	{21,21},
	{22,22},
	{23,23},
	{24,24},
	{25,25},
	{26,26},
	{27,27},
	{28,28},
	{29,29},
	{30,30},
	{31,31},
	{32,32},
	{33,33},
	{34,34},
	{35,35},
	{36,36},
	{37,37},
	{38,38},
	{39,39},
	{40,40},
	{41,41},
	{42,42},
	{43,43},
	{44,44},
	{45,45},
	{46,46},
	{47,47},
	{48,48},
	{49,49},
	{50,50},
	{51,51},
	{52,52},
	{53,53},
	{54,54},
	{55,55},
	{56,56},
	{57,57},
	{58,58},
	{59,59},
	{60,60},
	{61,61},
	{62,62},
	{63,63},
	{64,64},
	{65,65},
	{66,66},
	{67,67},
	{68,68},
	{69,69},
	{70,70},
	{71,71},
	{72,72},
	{73,73},
	{74,74},
	{75,75},
	{76,76},
	{77,77},
	{78,78},
	{79,79},
	{80,80},
	{81,81},
	{82,82},
	{83,83},
	{84,84},
	{85,85},
	{86,86},
	{87,87},
	{88,88},
	{89,89},
	{90,90},
	{91,91},
	{92,92},
	{93,93},
	{94,94},
	{95,95},
	{96,96},
	{97,97},
	{98,98},
	{99,99},
	{100,100},
	{101,101},
	{102,102},
	{103,103},
	{104,104},
	{105,105},
	{106,106},
	{107,107},
	{108,108},
	{109,109},
	{110,110},
	{111,111},
	{112,112},
	{113,113},
	{114,114},
	{115,115},
	{116,116},
	{117,117},
	{118,118},
	{119,119},
	{120,120},
	{121,121},
	{122,122},
	{123,123},
	{124,124},
	{125,125},
	{126,126},
	{127,127},
	{128,128},
	{129,129},
	{130,130},
	{131,131},
	{132,132},
	{133,133},
	{134,134},
	{135,135},
	{136,136},
	{137,137},
	{138,138},
	{139,139},
	{140,140},
	{141,141},
	{142,142},
	{143,143},
	{144,144},
	{145,145},
	{146,146},
	{147,147},
	{148,148},
	{149,149},
	{150,150},
	{151,151},
	{152,152},
	{153,153},
	{154,154},
	{155,155},
	{156,156},
	{157,157},
	{158,158},
	{159,159},
	{160,160},
	{161,161},
	{162,162},
	{163,163},
	{164,164},
	{165,165},
	{166,166},
	{167,167},
	{168,168},
	{169,169},
	{170,170},
	{171,171},
	{172,172},
	{173,173},
	{174,174},
	{175,175},
	{176,176},
	{177,177},
	{178,178},
	{179,179},
	{180,180},
	{181,181},
	{182,182},
	{183,183},
	{184,184},
	{185,185},
	{186,186},
	{187,187},
	{188,188},
	{189,189},
	{190,190},
	{191,191},
	{192,192},
	{193,193},
	{194,194},
	{195,195},
	{196,196},
	{197,197},
	{198,198},
	{199,199},
	{200,200},
	{201,201},
	{202,202},
	{203,203},
	{204,204},
	{205,205},
	{206,206},
	{207,207},
	{208,208},
	{209,209},
	{210,210},
	{211,211},
	{212,212},
	{213,213},
	{214,214},
	{215,215},
	{216,216},
	{217,217},
	{218,218},
	{219,219},
	{220,220},
	{221,221},
	{222,222},
	{223,223},
	{224,224},
	{225,225},
	{226,226},
	{227,227},
	{228,228},
	{229,229},
	{230,230},
	{231,231},
	{232,232},
	{233,233},
	{234,234},
	{235,235},
	{236,236},
	{237,237},
	{238,238},
	{239,239},
	{240,240},
	{241,241},
	{242,242},
	{243,243},
	{244,244},
	{245,245},
	{246,246},
	{247,247},
	{248,248},
	{249,249},
	{250,250},
	{251,251},
	{252,277},
	{253,278},
	{254,279},
	{255,280},
	{256,281},
	{257,282},
	{258,283},
	{259,284},
	{260,285},
	{261,286},
	{262,287},
	{263,288},
	{264,289},
	{265,290},
	{266,291},
	{267,292},
	{268,293},
	{269,294},
	{270,295},
	{271,296},
	{272,297},
	{273,298},
	{274,299},
	{275,300},
	{276,304},
	{277,305},
	{278,309},
	{279,310},
	{280,392},
	{281,393},
	{282,394},
	{283,311},
	{284,312},
	{285,306},
	{286,307},
	{287,364},
	{288,365},
	{289,366},
	{290,301},
	{291,302},
	{292,303},
	{293,370},
	{294,371},
	{295,372},
	{296,335},
	{297,336},
	{298,350},
	{299,320},
	{300,315},
	{301,316},
	{302,322},
	{303,355},
	{304,382},
	{305,383},
	{306,384},
	{307,356},
	{308,357},
	{309,337},
	{310,338},
	{311,353},
	{312,354},
	{313,386},
	{314,387},
	{315,363},
	{316,367},
	{317,368},
	{318,330},
	{319,331},
	{320,313},
	{321,314},
	{322,339},
	{323,340},
	{324,321},
	{325,351},
	{326,352},
	{327,308},
	{328,332},
	{329,333},
	{330,334},
	{331,344},
	{332,345},
	{333,358},
	{334,359},
	{335,380},
	{336,379},
	{337,348},
	{338,349},
	{339,323},
	{340,324},
	{341,326},
	{342,327},
	{343,318},
	{344,319},
	{345,388},
	{346,389},
	{347,390},
	{348,391},
	{349,328},
	{350,329},
	{351,385},
	{352,317},
	{353,377},
	{354,378},
	{355,361},
	{356,362},
	{357,369},
	{358,411},
	{359,376},
	{360,360},
	{361,346},
	{362,347},
	{363,341},
	{364,342},
	{365,343},
	{366,373},
	{367,374},
	{368,375},
	{369,381},
	{370,325},
	{371,395},
	{372,396},
	{373,397},
	{374,398},
	{375,399},
	{376,400},
	{377,401},
	{378,402},
	{379,403},
	{380,407},
	{381,408},
	{382,404},
	{383,405},
	{384,406},
	{385,409},
	{386,410}
};
GBASpecies::gbaspecies convertgbaspecies(int in)
{
	for(int i = 0; i < 386; i++)
	{
		if(in == int(dstogba[i][0]))
		{
			return GBASpecies::gbaspecies(dstogba[i][1]);
		}
	}
	return GBASpecies::NOTHING;
}
