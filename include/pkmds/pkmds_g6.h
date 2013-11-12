#include "../../include/pkmds/pkmds_g5.h"

namespace Species_g6
{
	enum pkxspecies : uint16 {
		NOTHING,
		bulbasaur,
		ivysaur,
		venusaur,
		charmander,
		charmeleon,
		charizard,
		squirtle,
		wartortle,
		blastoise,
		caterpie,
		metapod,
		butterfree,
		weedle,
		kakuna,
		beedrill,
		pidgey,
		pidgeotto,
		pidgeot,
		rattata,
		raticate,
		spearow,
		fearow,
		ekans,
		arbok,
		pikachu,
		raichu,
		sandshrew,
		sandslash,
		nidoran_f,
		nidorina,
		nidoqueen,
		nidoran_m,
		nidorino,
		nidoking,
		clefairy,
		clefable,
		vulpix,
		ninetales,
		jigglypuff,
		wigglytuff,
		zubat,
		golbat,
		oddish,
		gloom,
		vileplume,
		paras,
		parasect,
		venonat,
		venomoth,
		diglett,
		dugtrio,
		meowth,
		persian,
		psyduck,
		golduck,
		mankey,
		primeape,
		growlithe,
		arcanine,
		poliwag,
		poliwhirl,
		poliwrath,
		abra,
		kadabra,
		alakazam,
		machop,
		machoke,
		machamp,
		bellsprout,
		weepinbell,
		victreebel,
		tentacool,
		tentacruel,
		geodude,
		graveler,
		golem,
		ponyta,
		rapidash,
		slowpoke,
		slowbro,
		magnemite,
		magneton,
		farfetch_d,
		doduo,
		dodrio,
		seel,
		dewgong,
		grimer,
		muk,
		shellder,
		cloyster,
		gastly,
		haunter,
		gengar,
		onix,
		drowzee,
		hypno,
		krabby,
		kingler,
		voltorb,
		electrode,
		exeggcute,
		exeggutor,
		cubone,
		marowak,
		hitmonlee,
		hitmonchan,
		lickitung,
		koffing,
		weezing,
		rhyhorn,
		rhydon,
		chansey,
		tangela,
		kangaskhan,
		horsea,
		seadra,
		goldeen,
		seaking,
		staryu,
		starmie,
		mr_mime,
		scyther,
		jynx,
		electabuzz,
		magmar,
		pinsir,
		tauros,
		magikarp,
		gyarados,
		lapras,
		ditto,
		eevee,
		vaporeon,
		jolteon,
		flareon,
		porygon,
		omanyte,
		omastar,
		kabuto,
		kabutops,
		aerodactyl,
		snorlax,
		articuno,
		zapdos,
		moltres,
		dratini,
		dragonair,
		dragonite,
		mewtwo,
		mew,
		chikorita,
		bayleef,
		meganium,
		cyndaquil,
		quilava,
		typhlosion,
		totodile,
		croconaw,
		feraligatr,
		sentret,
		furret,
		hoothoot,
		noctowl,
		ledyba,
		ledian,
		spinarak,
		ariados,
		crobat,
		chinchou,
		lanturn,
		pichu,
		cleffa,
		igglybuff,
		togepi,
		togetic,
		natu,
		xatu,
		mareep,
		flaaffy,
		ampharos,
		bellossom,
		marill,
		azumarill,
		sudowoodo,
		politoed,
		hoppip,
		skiploom,
		jumpluff,
		aipom,
		sunkern,
		sunflora,
		yanma,
		wooper,
		quagsire,
		espeon,
		umbreon,
		murkrow,
		slowking,
		misdreavus,
		unown,
		wobbuffet,
		girafarig,
		pineco,
		forretress,
		dunsparce,
		gligar,
		steelix,
		snubbull,
		granbull,
		qwilfish,
		scizor,
		shuckle,
		heracross,
		sneasel,
		teddiursa,
		ursaring,
		slugma,
		magcargo,
		swinub,
		piloswine,
		corsola,
		remoraid,
		octillery,
		delibird,
		mantine,
		skarmory,
		houndour,
		houndoom,
		kingdra,
		phanpy,
		donphan,
		porygon2,
		stantler,
		smeargle,
		tyrogue,
		hitmontop,
		smoochum,
		elekid,
		magby,
		miltank,
		blissey,
		raikou,
		entei,
		suicune,
		larvitar,
		pupitar,
		tyranitar,
		lugia,
		ho_oh,
		celebi,
		treecko,
		grovyle,
		sceptile,
		torchic,
		combusken,
		blaziken,
		mudkip,
		marshtomp,
		swampert,
		poochyena,
		mightyena,
		zigzagoon,
		linoone,
		wurmple,
		silcoon,
		beautifly,
		cascoon,
		dustox,
		lotad,
		lombre,
		ludicolo,
		seedot,
		nuzleaf,
		shiftry,
		taillow,
		swellow,
		wingull,
		pelipper,
		ralts,
		kirlia,
		gardevoir,
		surskit,
		masquerain,
		shroomish,
		breloom,
		slakoth,
		vigoroth,
		slaking,
		nincada,
		ninjask,
		shedinja,
		whismur,
		loudred,
		exploud,
		makuhita,
		hariyama,
		azurill,
		nosepass,
		skitty,
		delcatty,
		sableye,
		mawile,
		aron,
		lairon,
		aggron,
		meditite,
		medicham,
		electrike,
		manectric,
		plusle,
		minun,
		volbeat,
		illumise,
		roselia,
		gulpin,
		swalot,
		carvanha,
		sharpedo,
		wailmer,
		wailord,
		numel,
		camerupt,
		torkoal,
		spoink,
		grumpig,
		spinda,
		trapinch,
		vibrava,
		flygon,
		cacnea,
		cacturne,
		swablu,
		altaria,
		zangoose,
		seviper,
		lunatone,
		solrock,
		barboach,
		whiscash,
		corphish,
		crawdaunt,
		baltoy,
		claydol,
		lileep,
		cradily,
		anorith,
		armaldo,
		feebas,
		milotic,
		castform,
		kecleon,
		shuppet,
		banette,
		duskull,
		dusclops,
		tropius,
		chimecho,
		absol,
		wynaut,
		snorunt,
		glalie,
		spheal,
		sealeo,
		walrein,
		clamperl,
		huntail,
		gorebyss,
		relicanth,
		luvdisc,
		bagon,
		shelgon,
		salamence,
		beldum,
		metang,
		metagross,
		regirock,
		regice,
		registeel,
		latias,
		latios,
		kyogre,
		groudon,
		rayquaza,
		jirachi,
		deoxys,
		turtwig,
		grotle,
		torterra,
		chimchar,
		monferno,
		infernape,
		piplup,
		prinplup,
		empoleon,
		starly,
		staravia,
		staraptor,
		bidoof,
		bibarel,
		kricketot,
		kricketune,
		shinx,
		luxio,
		luxray,
		budew,
		roserade,
		cranidos,
		rampardos,
		shieldon,
		bastiodon,
		burmy,
		wormadam,
		mothim,
		combee,
		vespiquen,
		pachirisu,
		buizel,
		floatzel,
		cherubi,
		cherrim,
		shellos,
		gastrodon,
		ambipom,
		drifloon,
		drifblim,
		buneary,
		lopunny,
		mismagius,
		honchkrow,
		glameow,
		purugly,
		chingling,
		stunky,
		skuntank,
		bronzor,
		bronzong,
		bonsly,
		mime_jr,
		happiny,
		chatot,
		spiritomb,
		gible,
		gabite,
		garchomp,
		munchlax,
		riolu,
		lucario,
		hippopotas,
		hippowdon,
		skorupi,
		drapion,
		croagunk,
		toxicroak,
		carnivine,
		finneon,
		lumineon,
		mantyke,
		snover,
		abomasnow,
		weavile,
		magnezone,
		lickilicky,
		rhyperior,
		tangrowth,
		electivire,
		magmortar,
		togekiss,
		yanmega,
		leafeon,
		glaceon,
		gliscor,
		mamoswine,
		porygon_z,
		gallade,
		probopass,
		dusknoir,
		froslass,
		rotom,
		uxie,
		mesprit,
		azelf,
		dialga,
		palkia,
		heatran,
		regigigas,
		giratina,
		cresselia,
		phione,
		manaphy,
		darkrai,
		shaymin,
		arceus,
		victini,
		snivy,
		servine,
		serperior,
		tepig,
		pignite,
		emboar,
		oshawott,
		dewott,
		samurott,
		patrat,
		watchog,
		lillipup,
		herdier,
		stoutland,
		purrloin,
		liepard,
		pansage,
		simisage,
		pansear,
		simisear,
		panpour,
		simipour,
		munna,
		musharna,
		pidove,
		tranquill,
		unfezant,
		blitzle,
		zebstrika,
		roggenrola,
		boldore,
		gigalith,
		woobat,
		swoobat,
		drilbur,
		excadrill,
		audino,
		timburr,
		gurdurr,
		conkeldurr,
		tympole,
		palpitoad,
		seismitoad,
		throh,
		sawk,
		sewaddle,
		swadloon,
		leavanny,
		venipede,
		whirlipede,
		scolipede,
		cottonee,
		whimsicott,
		petilil,
		lilligant,
		basculin,
		sandile,
		krokorok,
		krookodile,
		darumaka,
		darmanitan,
		maractus,
		dwebble,
		crustle,
		scraggy,
		scrafty,
		sigilyph,
		yamask,
		cofagrigus,
		tirtouga,
		carracosta,
		archen,
		archeops,
		trubbish,
		garbodor,
		zorua,
		zoroark,
		minccino,
		cinccino,
		gothita,
		gothorita,
		gothitelle,
		solosis,
		duosion,
		reuniclus,
		ducklett,
		swanna,
		vanillite,
		vanillish,
		vanilluxe,
		deerling,
		sawsbuck,
		emolga,
		karrablast,
		escavalier,
		foongus,
		amoonguss,
		frillish,
		jellicent,
		alomomola,
		joltik,
		galvantula,
		ferroseed,
		ferrothorn,
		klink,
		klang,
		klinklang,
		tynamo,
		eelektrik,
		eelektross,
		elgyem,
		beheeyem,
		litwick,
		lampent,
		chandelure,
		axew,
		fraxure,
		haxorus,
		cubchoo,
		beartic,
		cryogonal,
		shelmet,
		accelgor,
		stunfisk,
		mienfoo,
		mienshao,
		druddigon,
		golett,
		golurk,
		pawniard,
		bisharp,
		bouffalant,
		rufflet,
		braviary,
		vullaby,
		mandibuzz,
		heatmor,
		durant,
		deino,
		zweilous,
		hydreigon,
		larvesta,
		volcarona,
		cobalion,
		terrakion,
		virizion,
		tornadus,
		thundurus,
		reshiram,
		zekrom,
		landorus,
		kyurem,
		keldeo,
		meloetta,
		genesect,
		chespin,
quilladin,
chesnaught,
fennekin,
braixen,
delphox,
froakie,
frogadier,
greninja,
bunnelby,
diggersby,
fletchling,
fletchinder,
talonflame,
scatterbug,
spewpa,
vivillon,
litleo,
pyroar,
flabebe,
floette,
florges,
skiddo,
gogoat,
pancham,
pangoro,
furfrou,
espurr,
meowstic,
honedge,
doublade,
aegislash,
spritzee,
aromatisse,
swirlix,
slurpuff,
inkay,
malamar,
binacle,
barbaracle,
skrelp,
dragalge,
clauncher,
clawitzer,
helioptile,
heliolisk,
tyrunt,
tyrantrum,
amaura,
aurorus,
sylveon,
hawlucha,
dedenne,
carbink,
goomy,
sliggoo,
goodra,
klefki,
phantump,
trevenant,
pumpkaboo,
gourgeist,
bergmite,
avalugg,
noibat,
noivern,
xerneas,
yveltal,
zygarde,
		diancie,
		volcanion,
		hoopa
	};
}


// http://projectpokemon.org/wiki/Pokemon_X/Y_3DS_Structure
//Unencrypted Data
struct pkxunencryptblock { // The unencrypted block of the Pokemon data, featuring such important things as the PID and checksum.
	uint32 key; // Used for encryption / decryption.
	uint16 ispartydatadecrypted : 1;
	uint16 isboxdatadecrypted : 1;
	uint16 isspeciesegg : 1;
uint16 : 13;
	uint16 checksum; // The checksum for the Pokemon data; used to validate data.
	pkxunencryptblock()
	{
		memset(this,0,sizeof(pkxunencryptblock));
	}
};
struct pkxblocka { //
	Species_g6::pkxspecies species;
	Items::items item;
	uint16 tid;
	uint16 sid;
	uint32 exp;
	Abilities::abilities ability;
	byte abilitynum;
uint16 : 16;
	uint32 pid;
	Natures::natures nature;
	formsfield forms;
	evsfield evs;
uint32 : 32;
	byte unknown[3];
	pokerus pkrs;
uint32 : 32;
	uint32 kalosribbons;
	byte unknown2[12];
	pkxblocka()
	{
		memset(this,0,sizeof(pkxblocka));
	}
};
struct pkxblockb { //
#if ! defined(MARKUP_SIZEOFWCHAR)
#if __SIZEOF_WCHAR_T__ == 4 || __WCHAR_MAX__ > 0x10000
	char nickname[24];
#else
	wchar_t nickname[12];
#endif
#endif
uint16 : 16;
	Moves::moves moves[4];
	byte pp[4];
	byte ppups[4];
	Moves::moves eggmoves[4];
uint16 : 16;
	ivsfield ivs;
	pkxblockb()
	{
		memset(this,0,sizeof(pkxblockb));
	}
};
struct pkxblockc { //
#if ! defined(MARKUP_SIZEOFWCHAR)
#if __SIZEOF_WCHAR_T__ == 4 || __WCHAR_MAX__ > 0x10000
	char otname_to[24];
#else
	wchar_t otname_to[12];
#endif
#endif
	byte unknown[32];
	pkxblockc()
	{
		memset(this,0,sizeof(pkxblockc));
	}
};
struct pkxblockd { // 
#if ! defined(MARKUP_SIZEOFWCHAR)
#if __SIZEOF_WCHAR_T__ == 4 || __WCHAR_MAX__ > 0x10000
	char otname[24];
#else
	wchar_t otname[12];
#endif
#endif
	byte unknown[9]; // Unknown / unused
	datefield eggdate;
	datefield metdate;
byte : 8; // Unknown / unused
	Locations::locations eggmet;
	Locations::locations met;
	Balls::balls ball;
	metlevelfield metlevel_otgender;
byte : 8; // Unknown / unused
	Hometowns::hometowns hometown;
	Countries::countries country;
	byte regionid;
	byte regionid3ds;
	byte otlang;
uint32 : 32; // Unknown / unused
	pkxblockd()
	{
		memset(this,0,sizeof(pkxblockd));
	}
};
struct pokemonx_obj : pkxunencryptblock,pkxblocka,pkxblockb,pkxblockc,pkxblockd { // The Pokemon object, containing 232 bytes of data (as stored in the PC storage system)
	pokemonx_obj()
	{
		memset(this,0,sizeof(pokemonx_obj));
	}
};
struct partyx_field { // Size: 
	status_field status;
byte : 8;
uint16 : 16;
	byte level;
uint16 : 16;
byte : 8;
	uint16 hp;
	uint16 maxhp;
	uint16 attack;
	uint16 defense;
	uint16 speed;
	uint16 spatk;
	uint16 spdef;
uint16 : 16;
uint32 : 32;
	partyx_field()
	{
		memset(this,0,sizeof(partyx_field));
	}
};
struct party_pkx { // Size: 
	pokemonx_obj pkx_data;
	partyx_field partyx_data;
	party_pkx()
	{
		memset(this,0,sizeof(party_pkx));
	}
};
void DllExport pkmcrypt(partyx_field* pkx, uint32 pid);
void DllExport encryptpkm(party_pkx* pkx);
void DllExport decryptpkm(party_pkx* pkx);
byte DllExport getpkmshuffleindex(const pokemonx_obj *pkx);
void DllExport unshufflepkm(pokemonx_obj *pkx);
void DllExport shufflepkm(pokemonx_obj *pkx);
void DllExport pkmcrypt(pokemonx_obj* pkx);
void DllExport encryptpkm(pokemonx_obj* pkx);
void DllExport decryptpkm(pokemonx_obj* pkx);
void DllExport calcchecksum(pokemonx_obj* pkx);
void DllExport read(const char* file_name, pokemonx_obj *data);
void DllExport read(const wchar_t * file_name, pokemonx_obj *data);
void DllExport write(const char* file_name, pokemonx_obj* data);
void DllExport write(const wchar_t * file_name, pokemonx_obj* data);
bool DllExport getpkmshiny(const pokemonx_obj *pkx);
