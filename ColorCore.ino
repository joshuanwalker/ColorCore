#include <Micro_CircuitPlayground.h>
#include <Micro_Circuit_Playground.h>
#include "Micro_TCS34725.h"


/*
   Core System for ColorEye
*/


#define COLOR_NAMES_MAX 400
//declare the strings in progmem
const char color_data_1[] PROGMEM ="\xf0\xea\xd6Eggshell";
const char color_data_2[] PROGMEM ="\xff\x0\x3fElectric Crimson";
const char color_data_3[] PROGMEM ="\x0\x0\x0Black";
const char color_data_4[] PROGMEM ="\x26\x61\x9cLapis Lazuli";
const char color_data_5[] PROGMEM ="\x0\x31\x53Prussian Blue";
const char color_data_6[] PROGMEM ="\xff\x0\x0Red";
const char color_data_7[] PROGMEM ="\xff\x0\x7fRose";
const char color_data_8[] PROGMEM ="\x9f\x0\xc5Purple (Munsell)";
const char color_data_9[] PROGMEM ="\xff\x40\x40Coral Red";
const char color_data_10[] PROGMEM ="\xe3\xa8\x57Indian Yellow";
const char color_data_11[] PROGMEM ="\x0\x47\xabCobalt";
const char color_data_12[] PROGMEM ="\x55\x5d\x50Ebony";
const char color_data_13[] PROGMEM ="\x80\x80\x80Gray";
const char color_data_14[] PROGMEM ="\x0\x0\x80Navy Blue";
const char color_data_15[] PROGMEM ="\x0\xff\x0Electric Green";
const char color_data_16[] PROGMEM ="\xe0\x11\x5fRuby";
const char color_data_17[] PROGMEM ="\x0\x7f\xffAzure";
const char color_data_18[] PROGMEM ="\xff\xf6\x0Cadmium Yellow";
const char color_data_19[] PROGMEM ="\xf8\x83\x79Coral Pink";
const char color_data_20[] PROGMEM ="\xff\xc8\x7cTopaz";
const char color_data_21[] PROGMEM ="\x0\x38\xa8Royal Azure";
const char color_data_22[] PROGMEM ="\xff\x24\x0Scarlet";
const char color_data_23[] PROGMEM ="\xf0\xdc\x82Buff";
const char color_data_24[] PROGMEM ="\x7f\x0\xffViolet";
const char color_data_25[] PROGMEM ="\x7f\xff\x0Lime Green";
const char color_data_26[] PROGMEM ="\x1c\x39\xbbPersian Blue";
const char color_data_27[] PROGMEM ="\xff\xf7\x0Lemon";
const char color_data_28[] PROGMEM ="\xff\xff\xffWhite";
const char color_data_29[] PROGMEM ="\xcc\x55\x0Burnt Orange";
const char color_data_30[] PROGMEM ="\x3f\x0\xffElectric Ultramarine";
const char color_data_31[] PROGMEM ="\x29\xab\x87Jungle Green";
const char color_data_32[] PROGMEM ="\xfe\x4e\xdaPurple Pizzazz";
const char color_data_33[] PROGMEM ="\x0\xff\x7fSpring Green";
const char color_data_34[] PROGMEM ="\xff\x66\xccRose Pink";
const char color_data_35[] PROGMEM ="\x0\xa8\x6bJade";
const char color_data_36[] PROGMEM ="\x0\x7b\xa7Cerulean";
const char color_data_37[] PROGMEM ="\xff\x7f\x0Orange";
const char color_data_38[] PROGMEM ="\xff\x7f\x50Coral";
const char color_data_39[] PROGMEM ="\x7d\xf9\xffElectric Blue";
const char color_data_40[] PROGMEM ="\xbf\x0\xffElectric Purple";
const char color_data_41[] PROGMEM ="\xff\x0\xffFuchsia";
const char color_data_42[] PROGMEM ="\xe4\x71\x7aCandy Pink";
const char color_data_43[] PROGMEM ="\x0\x80\x80Teal";
const char color_data_44[] PROGMEM ="\x19\x19\x70Midnight Blue";
const char color_data_45[] PROGMEM ="\xff\xe1\x35Banana Yellow";
const char color_data_46[] PROGMEM ="\x0\x0\xffBlue";
const char color_data_47[] PROGMEM ="\x15\x60\xbdDenim";
const char color_data_48[] PROGMEM ="\xff\xff\xf0Ivory";
const char color_data_49[] PROGMEM ="\x1\x79\x6fPine Green";
const char color_data_50[] PROGMEM ="\xff\xc0\xcbPink";
const char color_data_51[] PROGMEM ="\x98\xff\x98Mint Green";
const char color_data_52[] PROGMEM ="\x0\xff\xffAqua";
const char color_data_53[] PROGMEM ="\x50\xc8\x78Emerald";
const char color_data_54[] PROGMEM ="\x0\x23\x66Royal Blue";
const char color_data_55[] PROGMEM ="\x61\x40\x51Eggplant";
const char color_data_56[] PROGMEM ="\xd2\xb4\x8cTan";
const char color_data_57[] PROGMEM ="\xff\xff\x0Yellow";
const char color_data_58[] PROGMEM ="\x99\x65\x15Golden Brown";
const char color_data_59[] PROGMEM ="\x10\x34\xa6Egyptian Blue";
const char color_data_60[] PROGMEM ="\xaa\x98\xa9Rose Quartz";
const char color_data_61[] PROGMEM ="\xfb\xce\xb1Apricot";
const char color_data_62[] PROGMEM ="\x0\x14\xa8Zaffre";
const char color_data_63[] PROGMEM ="\x91\x5f\x6dRaspberry Glace";
const char color_data_64[] PROGMEM ="\xfb\xab\x60Rajah";
const char color_data_65[] PROGMEM ="\xa4\xf4\xf9Waterspout";
const char color_data_66[] PROGMEM ="\xff\x69\x61Pastel Red";
const char color_data_67[] PROGMEM ="\xfc\xc2\x0Golden Poppy";
const char color_data_68[] PROGMEM ="\xde\x6f\xa1China Pink";
const char color_data_69[] PROGMEM ="\xa5\x71\x64Blast-Off Bronze";
const char color_data_70[] PROGMEM ="\x99\xba\xddCarolina Blue";
const char color_data_71[] PROGMEM ="\xfb\x99\x2Orange (Ryb)";
const char color_data_72[] PROGMEM ="\xba\x16\xcInternational Orange (Engineering)";
const char color_data_73[] PROGMEM ="\xee\xe8\xaaPale Goldenrod";
const char color_data_74[] PROGMEM ="\x0\x9e\x60Shamrock Green";
const char color_data_75[] PROGMEM ="\xd3\x0\x3fUtah Crimson";
const char color_data_76[] PROGMEM ="\x0\xf\x89Phthalo Blue";
const char color_data_77[] PROGMEM ="\xff\x14\x93Fluorescent Pink";
const char color_data_78[] PROGMEM ="\xff\x0\x4fFolly";
const char color_data_79[] PROGMEM ="\xcb\x6d\x51Copper Red";
const char color_data_80[] PROGMEM ="\xbc\xd4\xe6Pale Aqua";
const char color_data_81[] PROGMEM ="\x0\x75\x5eTropical Rain Forest";
const char color_data_82[] PROGMEM ="\xfd\xbc\xb4Melon";
const char color_data_83[] PROGMEM ="\xff\xe4\xe1Misty Rose";
const char color_data_84[] PROGMEM ="\x0\x87\xbdBlue (Ncs)";
const char color_data_85[] PROGMEM ="\x0\x67\xa5Sapphire Blue";
const char color_data_86[] PROGMEM ="\xd0\xf0\xc0Tea Green";
const char color_data_87[] PROGMEM ="\xe2\x72\x5bTerra Cotta";
const char color_data_88[] PROGMEM ="\xe9\x96\x7aDark Salmon";
const char color_data_89[] PROGMEM ="\xc4\xc3\xd0Lavender Gray";
const char color_data_90[] PROGMEM ="\x70\x1c\x1cPrune";
const char color_data_91[] PROGMEM ="\x70\x29\x63Byzantium";
const char color_data_92[] PROGMEM ="\xb5\xa6\x42Brass";
const char color_data_93[] PROGMEM ="\x3b\x44\x4bArsenic";
const char color_data_94[] PROGMEM ="\x9a\xcd\x32Yellow-Green";
const char color_data_95[] PROGMEM ="\xff\xa5\x0Orange (Web Color)";
const char color_data_96[] PROGMEM ="\x0\x70\xffBrandeis Blue";
const char color_data_97[] PROGMEM ="\xe0\xb0\xffMauve";
const char color_data_98[] PROGMEM ="\xf0\xf8\xffAlice Blue";
const char color_data_99[] PROGMEM ="\xb\xda\x51Malachite";
const char color_data_100[] PROGMEM ="\xc9\xc0\xbbPale Silver";
const char color_data_101[] PROGMEM ="\xff\xba\x0Selective Yellow";
const char color_data_102[] PROGMEM ="\x0\xa8\x77Green (Munsell)";
const char color_data_103[] PROGMEM ="\xf0\xff\xffAzure Mist/Web";
const char color_data_104[] PROGMEM ="\x3c\x34\x1fOlive Drab #7";
const char color_data_105[] PROGMEM ="\x0\x33\xaaUa Blue";
const char color_data_106[] PROGMEM ="\xe3\xb\x5dRaspberry";
const char color_data_107[] PROGMEM ="\xbf\x4f\x51Bittersweet Shimmer";
const char color_data_108[] PROGMEM ="\x98\xfb\x98Pale Green";
const char color_data_109[] PROGMEM ="\xe9\x74\x51Burnt Sienna";
const char color_data_110[] PROGMEM ="\x0\xce\xd1Dark Turquoise";
const char color_data_111[] PROGMEM ="\xe6\xbe\x8aPale Gold";
const char color_data_112[] PROGMEM ="\x1e\x90\xffDodger Blue";
const char color_data_113[] PROGMEM ="\xda\x91\x0Harvest Gold";
const char color_data_114[] PROGMEM ="\x9f\x81\x70Beaver";
const char color_data_115[] PROGMEM ="\x35\x38\x39Onyx";
const char color_data_116[] PROGMEM ="\x0\xff\xefTurquoise Blue";
const char color_data_117[] PROGMEM ="\x8f\x0\xffViolet Flower";
const char color_data_118[] PROGMEM ="\x98\x77\x7bBazaar";
const char color_data_119[] PROGMEM ="\xff\xcc\x0Tangerine Yellow";
const char color_data_120[] PROGMEM ="\xff\x99\x99Light Salmon Pink";
const char color_data_121[] PROGMEM ="\xfa\xd6\xa5Sunset";
const char color_data_122[] PROGMEM ="\xff\x4f\x0International Orange (Aerospace)";
const char color_data_123[] PROGMEM ="\x99\x32\xccDark Orchid";
const char color_data_124[] PROGMEM ="\x48\x3c\x32Taupe";
const char color_data_125[] PROGMEM ="\xff\x69\xb4Hot Pink";
const char color_data_126[] PROGMEM ="\x71\xa6\xd2Iceberg";
const char color_data_127[] PROGMEM ="\xae\xc6\xcfPastel Blue";
const char color_data_128[] PROGMEM ="\x53\x68\x95Ucla Blue";
const char color_data_129[] PROGMEM ="\x98\x81\x7bCinereous";
const char color_data_130[] PROGMEM ="\x73\xa9\xc2Moonstone Blue";
const char color_data_131[] PROGMEM ="\xff\xc1\xccBubble Gum";
const char color_data_132[] PROGMEM ="\xaa\xf0\xd1Magic Mint";
const char color_data_133[] PROGMEM ="\x70\x42\x14Sepia";
const char color_data_134[] PROGMEM ="\xff\xfa\xcdLemon Chiffon";
const char color_data_135[] PROGMEM ="\x43\xb3\xaeVerdigris";
const char color_data_136[] PROGMEM ="\x76\xff\x7aScreamin' Green";
const char color_data_137[] PROGMEM ="\x65\x43\x21Dark Brown";
const char color_data_138[] PROGMEM ="\xad\x6f\x69Copper Penny";
const char color_data_139[] PROGMEM ="\xbd\xb7\x6bDark Khaki";
const char color_data_140[] PROGMEM ="\x8b\x85\x89Taupe Gray";
const char color_data_141[] PROGMEM ="\x31\x8c\xe7Bleu De France";
const char color_data_142[] PROGMEM ="\x64\x54\x52Wenge";
const char color_data_143[] PROGMEM ="\xa0\xd6\xb4Turquoise Green";
const char color_data_144[] PROGMEM ="\xe3\xda\xc9Bone";
const char color_data_145[] PROGMEM ="\xc7\x15\x85Red-Violet";
const char color_data_146[] PROGMEM ="\xd2\x69\x1eCinnamon";
const char color_data_147[] PROGMEM ="\xdf\x73\xffHeliotrope";
const char color_data_148[] PROGMEM ="\xc3\x21\x48Bright Maroon";
const char color_data_149[] PROGMEM ="\xff\xdd\xf4Pink Lace";
const char color_data_150[] PROGMEM ="\x63\x51\x47Umber";
const char color_data_151[] PROGMEM ="\xff\x8\x0Candy Apple Red";
const char color_data_152[] PROGMEM ="\xec\xd5\x40Sandstorm";
const char color_data_153[] PROGMEM ="\x8a\x33\x24Burnt Umber";
const char color_data_154[] PROGMEM ="\x9a\xb9\x73Olivine";
const char color_data_155[] PROGMEM ="\x8\x78\x30La Salle Green";
const char color_data_156[] PROGMEM ="\xc9\xdc\x87Medium Spring Bud";
const char color_data_157[] PROGMEM ="\x87\xa9\x6bAsparagus";
const char color_data_158[] PROGMEM ="\x46\x82\xb4Steel Blue";
const char color_data_159[] PROGMEM ="\xf0\xe6\x8cLight Khaki";
const char color_data_160[] PROGMEM ="\xe1\xad\x21Urobilin";
const char color_data_161[] PROGMEM ="\xfb\xa0\xe3Lavender Rose";
const char color_data_162[] PROGMEM ="\x0\x93\xafBlue (Munsell)";
const char color_data_163[] PROGMEM ="\x91\x81\x51Dark Tan";
const char color_data_164[] PROGMEM ="\xff\xff\xe0Light Yellow";
const char color_data_165[] PROGMEM ="\x80\x0\x20Burgundy";
const char color_data_166[] PROGMEM ="\x60\x82\xb6Glaucous";
const char color_data_167[] PROGMEM ="\xcd\x7f\x32Bronze";
const char color_data_168[] PROGMEM ="\x80\x18\x18Falu Red";
const char color_data_169[] PROGMEM ="\xb7\x84\xa7Opera Mauve";
const char color_data_170[] PROGMEM ="\x3c\x14\x14Dark Sienna";
const char color_data_171[] PROGMEM ="\x0\x70\x3cDartmouth Green";
const char color_data_172[] PROGMEM ="\xde\xa5\xa4Pastel Pink";
const char color_data_173[] PROGMEM ="\x8a\x49\x6bTwilight Lavender";
const char color_data_174[] PROGMEM ="\x1a\x24\x21Dark Jungle Green";
const char color_data_175[] PROGMEM ="\x0\x42\x25British Racing Green";
const char color_data_176[] PROGMEM ="\xf2\x0\x3cRed (Munsell)";
const char color_data_177[] PROGMEM ="\x0\x80\x0Office Green";
const char color_data_178[] PROGMEM ="\xc8\xa2\xc8Lilac";
const char color_data_179[] PROGMEM ="\xf8\xf8\xffGhost White";
const char color_data_180[] PROGMEM ="\xe9\x69\x2cDeep Carrot Orange";
const char color_data_181[] PROGMEM ="\xff\xcb\xa4Deep Peach";
const char color_data_182[] PROGMEM ="\xfa\xda\xddPale Pink";
const char color_data_183[] PROGMEM ="\xf\xc0\xfcSpiro Disco Ball";
const char color_data_184[] PROGMEM ="\xfe\x27\x12Red (Ryb)";
const char color_data_185[] PROGMEM ="\x85\xbb\x65Dollar Bill";
const char color_data_186[] PROGMEM ="\xcc\x88\x99Puce";
const char color_data_187[] PROGMEM ="\xb8\x86\xbDark Goldenrod";
const char color_data_188[] PROGMEM ="\x0\x0\x9cDuke Blue";
const char color_data_189[] PROGMEM ="\x20\xb2\xaaLight Sea Green";
const char color_data_190[] PROGMEM ="\xff\xbc\xd9Cotton Candy";
const char color_data_191[] PROGMEM ="\x8b\x0\x8bDark Magenta";
const char color_data_192[] PROGMEM ="\xc7\x43\x75Fuchsia Rose";
const char color_data_193[] PROGMEM ="\x94\x0\xd3Dark Violet";
const char color_data_194[] PROGMEM ="\xfb\x60\x7fBrink Pink";
const char color_data_195[] PROGMEM ="\xff\xae\x42Yellow Orange";
const char color_data_196[] PROGMEM ="\xbd\x33\xa4Byzantine";
const char color_data_197[] PROGMEM ="\xda\x1d\x81Vivid Cerise";
const char color_data_198[] PROGMEM ="\xaf\x40\x35Medium Carmine";
const char color_data_199[] PROGMEM ="\x6c\xa0\xdcLittle Boy Blue";
const char color_data_200[] PROGMEM ="\xa7\x6b\xcfRich Lavender";
const char color_data_201[] PROGMEM ="\xa9\xa9\xa9Dark Gray";
const char color_data_202[] PROGMEM ="\x92\x27\x24Vivid Auburn";
const char color_data_203[] PROGMEM ="\xff\x63\x47Tomato";
const char color_data_204[] PROGMEM ="\xa\xba\xb5Tiffany Blue";
const char color_data_205[] PROGMEM ="\xe6\xe2\x0Peridot";
const char color_data_206[] PROGMEM ="\x0\xa6\x93Persian Green";
const char color_data_207[] PROGMEM ="\xbd\xda\x57June Bud";
const char color_data_208[] PROGMEM ="\xcf\xcf\xc4Pastel Gray";
const char color_data_209[] PROGMEM ="\x1\x32\x20Dark Green";
const char color_data_210[] PROGMEM ="\xb3\x8b\x6dLight Taupe";
const char color_data_211[] PROGMEM ="\x6c\x54\x1eField Drab";
const char color_data_212[] PROGMEM ="\x99\x66\xccAmethyst";
const char color_data_213[] PROGMEM ="\x79\x68\x78Old Lavender";
const char color_data_214[] PROGMEM ="\xff\xf0\xf5Lavender Blush";
const char color_data_215[] PROGMEM ="\xb2\xbe\xb5Ash Grey";
const char color_data_216[] PROGMEM ="\xb6\x66\xd2Rich Lilac";
const char color_data_217[] PROGMEM ="\x9f\x0\xffVivid Violet";
const char color_data_218[] PROGMEM ="\xb0\x30\x60Rich Maroon";
const char color_data_219[] PROGMEM ="\x53\x4b\x4fLiver";
const char color_data_220[] PROGMEM ="\xb7\x41\xeRust";
const char color_data_221[] PROGMEM ="\xa4\x0\x0Dark Candy Apple Red";
const char color_data_222[] PROGMEM ="\xf4\xa4\x60Sandy Brown";
const char color_data_223[] PROGMEM ="\xe0\x3c\x31Cg Red";
const char color_data_224[] PROGMEM ="\xef\xde\xcdAlmond";
const char color_data_225[] PROGMEM ="\x86\x60\x8eFrench Lilac";
const char color_data_226[] PROGMEM ="\x18\x45\x3bMsu Green";
const char color_data_227[] PROGMEM ="\xbe\xbe\xbeGray (X11 Gray)";
const char color_data_228[] PROGMEM ="\xfb\xae\xd2Lavender Pink";
const char color_data_229[] PROGMEM ="\x0\x41\x6aDark Imperial Blue";
const char color_data_230[] PROGMEM ="\xf7\x8f\xa7Pink Sherbet";
const char color_data_231[] PROGMEM ="\x34\x34\x34Jet";
const char color_data_232[] PROGMEM ="\xd6\xca\xddLanguid Lavender";
const char color_data_233[] PROGMEM ="\xb2\x22\x22Firebrick";
const char color_data_234[] PROGMEM ="\x73\x4f\x96Dark Lavender";
const char color_data_235[] PROGMEM ="\x66\x38\x54Halayα ·Be";
const char color_data_236[] PROGMEM ="\x74\xc3\x65Mantis";
const char color_data_237[] PROGMEM ="\xff\xa0\x7aLight Salmon";
const char color_data_238[] PROGMEM ="\xff\x0\x38Carmine Red";
const char color_data_239[] PROGMEM ="\xf9\x42\x9eRose Bonbon";
const char color_data_240[] PROGMEM ="\xfd\xf5\xe6Old Lace";
const char color_data_241[] PROGMEM ="\x67\x4c\x47Medium Taupe";
const char color_data_242[] PROGMEM ="\xdc\xd0\xffPale Lavender";
const char color_data_243[] PROGMEM ="\x6\x2a\x78Catalina Blue";
const char color_data_244[] PROGMEM ="\xe6\x8f\xacCharm Pink";
const char color_data_245[] PROGMEM ="\xcc\x77\x22Ochre";
const char color_data_246[] PROGMEM ="\xfd\xd5\xb1Light Apricot";
const char color_data_247[] PROGMEM ="\xf1\xa7\xfeRich Brilliant Lavender";
const char color_data_248[] PROGMEM ="\xa2\xad\xd0Wild Blue Yonder";
const char color_data_249[] PROGMEM ="\xff\x35\x5eRadical Red";
const char color_data_250[] PROGMEM ="\xe7\xfe\xffBubbles";
const char color_data_251[] PROGMEM ="\xda\x70\xd6Orchid";
const char color_data_252[] PROGMEM ="\xd7\xa\x53Debian Red";
const char color_data_253[] PROGMEM ="\xcb\x41\x54Brick Red";
const char color_data_254[] PROGMEM ="\xfa\xfa\xd2Light Goldenrod Yellow";
const char color_data_255[] PROGMEM ="\x89\xcf\xf0Baby Blue";
const char color_data_256[] PROGMEM ="\x21\x42\x1eMyrtle";
const char color_data_257[] PROGMEM ="\xed\x87\x2dCadmium Orange";
const char color_data_258[] PROGMEM ="\xb5\x65\x1dLight Brown";
const char color_data_259[] PROGMEM ="\xfa\xf0\xe6Linen";
const char color_data_260[] PROGMEM ="\x35\x5e\x3bHunter Green";
const char color_data_261[] PROGMEM ="\x77\x9e\xcbDark Pastel Blue";
const char color_data_262[] PROGMEM ="\xf0\xff\xf0Honeydew";
const char color_data_263[] PROGMEM ="\x22\x8b\x22Forest Green (Web)";
const char color_data_264[] PROGMEM ="\xdc\xdc\xdcGainsboro";
const char color_data_265[] PROGMEM ="\xff\xcc\x33Sunglow";
const char color_data_266[] PROGMEM ="\x8a\x2b\xe2Blue-Violet";
const char color_data_267[] PROGMEM ="\xff\xfa\xf0Floral White";
const char color_data_268[] PROGMEM ="\x68\x28\x60Palatinate Purple";
const char color_data_269[] PROGMEM ="\x9d\xc2\x9Limerick";
const char color_data_270[] PROGMEM ="\xe5\xaa\x70Fawn";
const char color_data_271[] PROGMEM ="\xff\x38\x0Coquelicot";
const char color_data_272[] PROGMEM ="\x80\x0\x0Maroon (Html/Css)";
const char color_data_273[] PROGMEM ="\xc5\x4b\x8cMulberry";
const char color_data_274[] PROGMEM ="\xff\x55\xa3Brilliant Rose";
const char color_data_275[] PROGMEM ="\x4b\x0\x82Indigo (Web)";
const char color_data_276[] PROGMEM ="\xe8\x0\xdKu Crimson";
const char color_data_277[] PROGMEM ="\xde\x5d\x83Blush";
const char color_data_278[] PROGMEM ="\xfe\x28\xa2Persian Rose";
const char color_data_279[] PROGMEM ="\xf8\xb8\x78Mellow Apricot";
const char color_data_280[] PROGMEM ="\xf2\x85\x0Tangerine";
const char color_data_281[] PROGMEM ="\x50\x7d\x2aSap Green";
const char color_data_282[] PROGMEM ="\xa5\x2a\x2aAuburn";
const char color_data_283[] PROGMEM ="\x46\x59\x45Gray-Asparagus";
const char color_data_284[] PROGMEM ="\x74\x6c\xc0Toolbox";
const char color_data_285[] PROGMEM ="\xff\x33\xccRazzle Dazzle Rose";
const char color_data_286[] PROGMEM ="\x23\x29\x7aSt. Patrick'S Blue";
const char color_data_287[] PROGMEM ="\x96\x0\x18Carmine";
const char color_data_288[] PROGMEM ="\xcc\x33\x33Persian Red";
const char color_data_289[] PROGMEM ="\xc0\x40\x0Mahogany";
const char color_data_290[] PROGMEM ="\xff\x77\xffFuchsia Pink";
const char color_data_291[] PROGMEM ="\xfd\xdd\xe6Piggy Pink";
const char color_data_292[] PROGMEM ="\xff\xb3\x47Pastel Orange";
const char color_data_293[] PROGMEM ="\xa5\xb\x5eJazzberry Jam";
const char color_data_294[] PROGMEM ="\x99\x66\x66Copper Rose";
const char color_data_295[] PROGMEM ="\x87\xce\xebSky Blue";
const char color_data_296[] PROGMEM ="\xfe\x41\x64Neon Fuchsia";
const char color_data_297[] PROGMEM ="\x6f\x0\xffIndigo";
const char color_data_298[] PROGMEM ="\x90\xee\x90Light Green";
const char color_data_299[] PROGMEM ="\xe3\x0\x22Cadmium Red";
const char color_data_300[] PROGMEM ="\xcd\x5b\x45Dark Coral";
const char color_data_301[] PROGMEM ="\xda\x32\x87Deep Cerise";
const char color_data_302[] PROGMEM ="\xbe\x0\x32Crimson Glory";
const char color_data_303[] PROGMEM ="\xf9\x4d\x0Tangelo";
const char color_data_304[] PROGMEM ="\x48\x6\x7Bulgarian Rose";
const char color_data_305[] PROGMEM ="\x83\x69\x53Pastel Brown";
const char color_data_306[] PROGMEM ="\x66\xb0\x32Green (Ryb)";
const char color_data_307[] PROGMEM ="\xf4\xf0\xecIsabelline";
const char color_data_308[] PROGMEM ="\xb3\x44\x6cRaspberry Rose";
const char color_data_309[] PROGMEM ="\x2f\x84\x7cCeladon Green";
const char color_data_310[] PROGMEM ="\xff\xda\xb9Peach Puff";
const char color_data_311[] PROGMEM ="\xff\x0\x90Magenta (Process)";
const char color_data_312[] PROGMEM ="\x30\xba\x8fMountain Meadow";
const char color_data_313[] PROGMEM ="\x0\x6a\x4eBottle Green";
const char color_data_314[] PROGMEM ="\x96\x71\x17Sand Dune";
const char color_data_315[] PROGMEM ="\xa0\x78\x5aChamoisee";
const char color_data_316[] PROGMEM ="\xc1\x9a\x6bWood Brown";
const char color_data_317[] PROGMEM ="\x0\x4b\x49Deep Jungle Green";
const char color_data_318[] PROGMEM ="\x0\x49\x53Midnight Green (Eagle Green)";
const char color_data_319[] PROGMEM ="\x6e\x7f\x80Aurometalsaurus";
const char color_data_320[] PROGMEM ="\x0\x77\xbeOcean Boat Blue";
const char color_data_321[] PROGMEM ="\xff\x99\x66Atomic Tangerine";
const char color_data_322[] PROGMEM ="\x98\x76\x54Pale Brown";
const char color_data_323[] PROGMEM ="\xa1\xca\xf1Baby Blue Eyes";
const char color_data_324[] PROGMEM ="\xe1\xa9\x5fEarth Yellow";
const char color_data_325[] PROGMEM ="\xe6\xe8\xfaGlitter";
const char color_data_326[] PROGMEM ="\xc7\x2c\x48French Raspberry";
const char color_data_327[] PROGMEM ="\xfc\x8e\xacFlamingo Pink";
const char color_data_328[] PROGMEM ="\x6a\x5a\xcdSlate Blue";
const char color_data_329[] PROGMEM ="\x0\x30\x8fAir Force Blue";
const char color_data_330[] PROGMEM ="\xe3\x25\x6bRazzmatazz";
const char color_data_331[] PROGMEM ="\xff\xdd\xcaUnbleached Silk";
const char color_data_332[] PROGMEM ="\xd7\x83\x7fNew York Pink";
const char color_data_333[] PROGMEM ="\x96\xde\xd1Pale Robin Egg Blue";
const char color_data_334[] PROGMEM ="\xa8\x51\x6eChina Rose";
const char color_data_335[] PROGMEM ="\xc4\x62\x10Alloy Orange";
const char color_data_336[] PROGMEM ="\xb8\x73\x33Copper";
const char color_data_337[] PROGMEM ="\xcf\xb5\x3bOld Gold";
const char color_data_338[] PROGMEM ="\xa4\xdd\xedNon-Photo Blue";
const char color_data_339[] PROGMEM ="\x0\x74\x74Skobeloff";
const char color_data_340[] PROGMEM ="\xb7\x6e\x79Rose Gold";
const char color_data_341[] PROGMEM ="\xb4\x83\x95English Lavender";
const char color_data_342[] PROGMEM ="\xe2\x58\x22Flame";
const char color_data_343[] PROGMEM ="\x3c\xb3\x71Medium Sea Green";
const char color_data_344[] PROGMEM ="\xec\xeb\xbdPale Spring Bud";
const char color_data_345[] PROGMEM ="\xd1\xe2\x31Pear";
const char color_data_346[] PROGMEM ="\x5b\x92\xe5United Nations Blue";
const char color_data_347[] PROGMEM ="\x78\x51\xa9Royal Purple";
const char color_data_348[] PROGMEM ="\xff\xf5\xeeSeashell";
const char color_data_349[] PROGMEM ="\xf9\x84\xe5Pale Magenta";
const char color_data_350[] PROGMEM ="\x92\xa1\xcfCeil";
const char color_data_351[] PROGMEM ="\x36\x45\x4fCharcoal";
const char color_data_352[] PROGMEM ="\x1f\x75\xfeBlue (Crayola)";
const char color_data_353[] PROGMEM ="\x8b\x45\x13Saddle Brown";
const char color_data_354[] PROGMEM ="\xcf\x10\x20Lava";
const char color_data_355[] PROGMEM ="\xca\x1f\x7bMagenta (Dye)";
const char color_data_356[] PROGMEM ="\xee\x82\xeeLavender Magenta";
const char color_data_357[] PROGMEM ="\x0\xa5\x50Green (Pigment)";
const char color_data_358[] PROGMEM ="\xf9\x84\xefLight Fuchsia Pink";
const char color_data_359[] PROGMEM ="\xf5\xf5\xdcBeige";
const char color_data_360[] PROGMEM ="\xc4\x2\x33Red (Ncs)";
const char color_data_361[] PROGMEM ="\xfc\x6c\x85Wild Watermelon";
const char color_data_362[] PROGMEM ="\x1c\x35\x2dMedium Jungle Green";
const char color_data_363[] PROGMEM ="\x66\x42\x4dDeep Tuscan Red";
const char color_data_364[] PROGMEM ="\x78\x18\x4aPansy Purple";
const char color_data_365[] PROGMEM ="\xff\x28\x0Ferrari Red";
const char color_data_366[] PROGMEM ="\x0\x0\xcdMedium Blue";
const char color_data_367[] PROGMEM ="\xc5\xb3\x58Vegas Gold";
const char color_data_368[] PROGMEM ="\x0\x6b\x3cCadmium Green";
const char color_data_369[] PROGMEM ="\x80\x46\x1bRusset";
const char color_data_370[] PROGMEM ="\x0\x33\x66Dark Midnight Blue";
const char color_data_371[] PROGMEM ="\x0\x42\x42Warm Black";
const char color_data_372[] PROGMEM ="\x60\x50\xdcMajorelle Blue";
const char color_data_373[] PROGMEM ="\x2c\x16\x8Zinnwaldite Brown";
const char color_data_374[] PROGMEM ="\x5f\x9e\xa0Cadet Blue";
const char color_data_375[] PROGMEM ="\xdf\x0\xffPsychedelic Purple";
const char color_data_376[] PROGMEM ="\x8\x45\x7eDark Cerulean";
const char color_data_377[] PROGMEM ="\xe1\x8e\x96Ruddy Pink";
const char color_data_378[] PROGMEM ="\xe0\xff\xffLight Cyan";
const char color_data_379[] PROGMEM ="\x6d\x9b\xc3Cerulean Frost";
const char color_data_380[] PROGMEM ="\xf0\x80\x80Light Coral";
const char color_data_381[] PROGMEM ="\xcc\xff\x0French Lime";
const char color_data_382[] PROGMEM ="\xf5\xf5\xf5White Smoke";
const char color_data_383[] PROGMEM ="\xfd\xee\x0Aureolin";
const char color_data_384[] PROGMEM ="\x73\x86\x78Xanadu";
const char color_data_385[] PROGMEM ="\xec\x3b\x83Cerise Pink";
const char color_data_386[] PROGMEM ="\x97\x9a\xaaManatee";
const char color_data_387[] PROGMEM ="\x69\x69\x69Dim Gray";
const char color_data_388[] PROGMEM ="\xfe\x6f\x5eBittersweet";
const char color_data_389[] PROGMEM ="\x8e\x45\x85Plum (Traditional)";
const char color_data_390[] PROGMEM ="\x73\xc2\xfbMaya Blue";
const char color_data_391[] PROGMEM ="\x79\x44\x3bMedium Tuscan Red";
const char color_data_392[] PROGMEM ="\xd4\xaf\x37Gold (Metallic)";
const char color_data_393[] PROGMEM ="\x7b\x68\xeeMedium Slate Blue";
const char color_data_394[] PROGMEM ="\xa0\x20\xf0Veronica";
const char color_data_395[] PROGMEM ="\x55\x6b\x2fDark Olive Green";
const char color_data_396[] PROGMEM ="\xcd\x5c\x5cChestnut";
const char color_data_397[] PROGMEM ="\x0\xb7\xebCyan (Process)";
const char color_data_398[] PROGMEM ="\x0\x40\x40Rich Black";
const char color_data_399[] PROGMEM ="\xbc\x8f\x8fRosy Brown";
const char color_data_400[] PROGMEM ="\x0\x73\xcfTrue Blue";


//declare the table
const char *color_data[] = {
color_data_1,
color_data_2,
color_data_3,
color_data_4,
color_data_5,
color_data_6,
color_data_7,
color_data_8,
color_data_9,
color_data_10,
color_data_11,
color_data_12,
color_data_13,
color_data_14,
color_data_15,
color_data_16,
color_data_17,
color_data_18,
color_data_19,
color_data_20,
color_data_21,
color_data_22,
color_data_23,
color_data_24,
color_data_25,
color_data_26,
color_data_27,
color_data_28,
color_data_29,
color_data_30,
color_data_31,
color_data_32,
color_data_33,
color_data_34,
color_data_35,
color_data_36,
color_data_37,
color_data_38,
color_data_39,
color_data_40,
color_data_41,
color_data_42,
color_data_43,
color_data_44,
color_data_45,
color_data_46,
color_data_47,
color_data_48,
color_data_49,
color_data_50,
color_data_51,
color_data_52,
color_data_53,
color_data_54,
color_data_55,
color_data_56,
color_data_57,
color_data_58,
color_data_59,
color_data_60,
color_data_61,
color_data_62,
color_data_63,
color_data_64,
color_data_65,
color_data_66,
color_data_67,
color_data_68,
color_data_69,
color_data_70,
color_data_71,
color_data_72,
color_data_73,
color_data_74,
color_data_75,
color_data_76,
color_data_77,
color_data_78,
color_data_79,
color_data_80,
color_data_81,
color_data_82,
color_data_83,
color_data_84,
color_data_85,
color_data_86,
color_data_87,
color_data_88,
color_data_89,
color_data_90,
color_data_91,
color_data_92,
color_data_93,
color_data_94,
color_data_95,
color_data_96,
color_data_97,
color_data_98,
color_data_99,
color_data_100,
color_data_101,
color_data_102,
color_data_103,
color_data_104,
color_data_105,
color_data_106,
color_data_107,
color_data_108,
color_data_109,
color_data_110,
color_data_111,
color_data_112,
color_data_113,
color_data_114,
color_data_115,
color_data_116,
color_data_117,
color_data_118,
color_data_119,
color_data_120,
color_data_121,
color_data_122,
color_data_123,
color_data_124,
color_data_125,
color_data_126,
color_data_127,
color_data_128,
color_data_129,
color_data_130,
color_data_131,
color_data_132,
color_data_133,
color_data_134,
color_data_135,
color_data_136,
color_data_137,
color_data_138,
color_data_139,
color_data_140,
color_data_141,
color_data_142,
color_data_143,
color_data_144,
color_data_145,
color_data_146,
color_data_147,
color_data_148,
color_data_149,
color_data_150,
color_data_151,
color_data_152,
color_data_153,
color_data_154,
color_data_155,
color_data_156,
color_data_157,
color_data_158,
color_data_159,
color_data_160,
color_data_161,
color_data_162,
color_data_163,
color_data_164,
color_data_165,
color_data_166,
color_data_167,
color_data_168,
color_data_169,
color_data_170,
color_data_171,
color_data_172,
color_data_173,
color_data_174,
color_data_175,
color_data_176,
color_data_177,
color_data_178,
color_data_179,
color_data_180,
color_data_181,
color_data_182,
color_data_183,
color_data_184,
color_data_185,
color_data_186,
color_data_187,
color_data_188,
color_data_189,
color_data_190,
color_data_191,
color_data_192,
color_data_193,
color_data_194,
color_data_195,
color_data_196,
color_data_197,
color_data_198,
color_data_199,
color_data_200,
color_data_201,
color_data_202,
color_data_203,
color_data_204,
color_data_205,
color_data_206,
color_data_207,
color_data_208,
color_data_209,
color_data_210,
color_data_211,
color_data_212,
color_data_213,
color_data_214,
color_data_215,
color_data_216,
color_data_217,
color_data_218,
color_data_219,
color_data_220,
color_data_221,
color_data_222,
color_data_223,
color_data_224,
color_data_225,
color_data_226,
color_data_227,
color_data_228,
color_data_229,
color_data_230,
color_data_231,
color_data_232,
color_data_233,
color_data_234,
color_data_235,
color_data_236,
color_data_237,
color_data_238,
color_data_239,
color_data_240,
color_data_241,
color_data_242,
color_data_243,
color_data_244,
color_data_245,
color_data_246,
color_data_247,
color_data_248,
color_data_249,
color_data_250,
color_data_251,
color_data_252,
color_data_253,
color_data_254,
color_data_255,
color_data_256,
color_data_257,
color_data_258,
color_data_259,
color_data_260,
color_data_261,
color_data_262,
color_data_263,
color_data_264,
color_data_265,
color_data_266,
color_data_267,
color_data_268,
color_data_269,
color_data_270,
color_data_271,
color_data_272,
color_data_273,
color_data_274,
color_data_275,
color_data_276,
color_data_277,
color_data_278,
color_data_279,
color_data_280,
color_data_281,
color_data_282,
color_data_283,
color_data_284,
color_data_285,
color_data_286,
color_data_287,
color_data_288,
color_data_289,
color_data_290,
color_data_291,
color_data_292,
color_data_293,
color_data_294,
color_data_295,
color_data_296,
color_data_297,
color_data_298,
color_data_299,
color_data_300,
color_data_301,
color_data_302,
color_data_303,
color_data_304,
color_data_305,
color_data_306,
color_data_307,
color_data_308,
color_data_309,
color_data_310,
color_data_311,
color_data_312,
color_data_313,
color_data_314,
color_data_315,
color_data_316,
color_data_317,
color_data_318,
color_data_319,
color_data_320,
color_data_321,
color_data_322,
color_data_323,
color_data_324,
color_data_325,
color_data_326,
color_data_327,
color_data_328,
color_data_329,
color_data_330,
color_data_331,
color_data_332,
color_data_333,
color_data_334,
color_data_335,
color_data_336,
color_data_337,
color_data_338,
color_data_339,
color_data_340,
color_data_341,
color_data_342,
color_data_343,
color_data_344,
color_data_345,
color_data_346,
color_data_347,
color_data_348,
color_data_349,
color_data_350,
color_data_351,
color_data_352,
color_data_353,
color_data_354,
color_data_355,
color_data_356,
color_data_357,
color_data_358,
color_data_359,
color_data_360,
color_data_361,
color_data_362,
color_data_363,
color_data_364,
color_data_365,
color_data_366,
color_data_367,
color_data_368,
color_data_369,
color_data_370,
color_data_371,
color_data_372,
color_data_373,
color_data_374,
color_data_375,
color_data_376,
color_data_377,
color_data_378,
color_data_379,
color_data_380,
color_data_381,
color_data_382,
color_data_383,
color_data_384,
color_data_385,
color_data_386,
color_data_387,
color_data_388,
color_data_389,
color_data_390,
color_data_391,
color_data_392,
color_data_393,
color_data_394,
color_data_395,
color_data_396,
color_data_397,
color_data_398,
color_data_399,
color_data_400
};



enum menu_items
{
  words,
  rgbtalk,
  hsltalk,
  sparkle,
};


uint16_t cap_r, cap_g, cap_b, c;

int menu = 0;             // counter for the number of button presses
int LbuttonState = 0;     // current state of the left button
int LlastButtonState = 0; // previous state of the left button
int RbuttonState = 0;     // current state of the right button
int RlastButtonState = 0; // previous state of the right button

char shadestring[30];
char colorstring[30];
char colorspeak[80];
char RGBspeak[100];
char HSLspeak[100];
byte cap_red;
byte cap_green;
byte cap_blue;
int h;
int s;
int l;



void setup()
{
  //Much of this is just wasting time until the EMIC2 powers up.
  int i = 0;

  //Start Up playground
  CircuitPlayground.begin();
  Serial.begin(9600);
  Serial1.begin(9600);

  //Rotate colors for startup
  CircuitPlayground.clearPixels();
  for (i = 0; i < 10; ++i)
  {
    delay(200);
    CircuitPlayground.strip.setPixelColor(i, CircuitPlayground.colorWheel(((i * 256 / 10)) & 255));
    CircuitPlayground.strip.show();
  }

  //Test Eyeball light
  pinMode(10, OUTPUT);
  digitalWrite(10, HIGH);
  delay(500);
  digitalWrite(10, LOW);
  CircuitPlayground.clearPixels();


  //Beep beep I'm a sheep!
  CircuitPlayground.playTone(3000, 200);
  delay(50);
  CircuitPlayground.playTone(3000, 200);

  //Set speech voice 
  Serial1.println("N3");
  delay(50);
  
  //Set Speech Volume
  Serial1.println("V17");
  delay(50);

  //set Speech speed
  if (CircuitPlayground.slideSwitch() == false)
    {Serial1.println("W200"); delay(50);}
  else
    {Serial1.println("W400"); delay(50);}
}

void loop()
{
  //Select Menu Item
  //Menus
  //0 - Words
  //1 - RGBTalk
  //2 - HSLTalk
  //3 - Sparkle
  LbuttonState = CircuitPlayground.leftButton();
  // compare the buttonState to its previous state
  if (LbuttonState != LlastButtonState)
  {
    // if the state has changed, increment the counter
    if (LbuttonState == true)
    {
      // if the current state is HIGH then the button went from off to on:
      menu++;
      if (menu > 3)
      {
        menu = 0;
      }
      CircuitPlayground.playTone(2000 + (100 * menu), 50);
    }
    // Delay a little bit to avoid bouncing
    delay(50);
  }
  // save the current state as the last state, for next time through the loop
  LlastButtonState = LbuttonState;

  //Execute Menu option
  RbuttonState = CircuitPlayground.rightButton();
  // compare the buttonState to its previous state
  if (RbuttonState != RlastButtonState)
  {
    // if the state has changed, increment the counter
    if (RbuttonState == true)
    {
      CircuitPlayground.playTone(1000, 50);
      // if the current state is HIGH then the button went from off to on:
      switch (menu)
      {
      case words:
        do_words();
        break;
      case rgbtalk:
        do_rgbtalk();
        break;
      case hsltalk:
        do_hsltalk();
        break;
      case sparkle:
        do_sparkle();
        break;
      }
    }
    // Delay a little bit to avoid bouncing
    delay(50);
  }
  RlastButtonState = RbuttonState;
}

void do_words(void)
{
    uint32_t sum;
    float r,g,b;
		shadestring[0] = '\0';
		colorspeak[0] = '\0';
		RGBspeak[0] = '\0';
		HSLspeak[0] = '\0';

  //power up Eyeball
  digitalWrite(10, HIGH);
  delay(60);
  Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_700MS, TCS34725_GAIN_4X);
  if (tcs.begin()) {
      CircuitPlayground.playTone(1000, 100);
      CircuitPlayground.playTone(1500, 100);
  } else {while(1);}
delay (1000);
  do
  {


  tcs.getRawData(&cap_r, &cap_g, &cap_b, &c);

  
//   Serial.print("C:\t"); Serial.print(c);
//   Serial.print("\tR:\t"); Serial.print(cap_r);
//   Serial.print("\tG:\t"); Serial.print(cap_g);
//   Serial.print("\tB:\t"); Serial.print(cap_b);
//  Serial.println();




  scale_cap();


  Serial.print("C:\t"); Serial.print(c);
  Serial.print("\tR:\t"); Serial.print(cap_red);
  Serial.print("\tG:\t"); Serial.print(cap_green);
  Serial.print("\tB:\t"); Serial.print(cap_blue);
 Serial.println();




  } while  (!CircuitPlayground.leftButton() && !CircuitPlayground.rightButton());
  digitalWrite(10, LOW);

  find_color(cap_red, cap_green, cap_blue);
  //Serial.println(colorstring);

	RGBtoHSL(cap_red, cap_green, cap_blue);
	getshade();
  
  sprintf(colorspeak, "S%s : Shade of %s", colorstring, shadestring);
  setspeed();
  Serial.println(colorspeak);
  Serial1.println();
  Serial1.println(colorspeak);

  CircuitPlayground.playTone(1500, 100);
  CircuitPlayground.playTone(1000, 100);
}

void do_rgbtalk(void)
{
  CircuitPlayground.playTone(1000, 100);
  CircuitPlayground.playTone(1500, 100);
  setspeed();
  Serial.println(colorspeak);
  sprintf(RGBspeak, "S%s : Shade of %s. R = %d, G = %d, B = %d\n", colorstring, shadestring, cap_red, cap_green, cap_blue);
   Serial1.println();
  Serial1.println(RGBspeak);
}

void do_hsltalk(void)
{
  CircuitPlayground.playTone(1000, 100);
  CircuitPlayground.playTone(1500, 100);
  setspeed();
  Serial.println(colorspeak);
  sprintf(HSLspeak, "S%s : Shade of %s. H = %d, S = %d, L = %d\n", colorstring, shadestring, h, s, l);
   Serial1.println();
  Serial1.println(HSLspeak);
}

void do_sparkle(void)
{
  int currentpixel;
  int lastpixel;
  CircuitPlayground.playTone(1000, 100);
  CircuitPlayground.playTone(1500, 100);
  delay(50);
  do
  {
    shake:
    currentpixel = random(9);
    if (currentpixel == lastpixel) {goto shake; }
    CircuitPlayground.strip.setPixelColor(random(9), random(255), random(255), random(255));
    CircuitPlayground.strip.show();
    delay(50);
    CircuitPlayground.clearPixels();
    lastpixel=currentpixel;
  } while (!CircuitPlayground.leftButton() && !CircuitPlayground.rightButton());
  CircuitPlayground.playTone(1500, 100);
  CircuitPlayground.playTone(1000, 100);
}

void scale_cap(void)
{
  // cap_red = cap_r / 256 * (c/256);
  // cap_green = cap_g / 256 * (c/256);
  // cap_blue = cap_b / 256 * (c/256);

  cap_red = cap_r / 256;
  cap_green = cap_g / 256;
  cap_blue = cap_b / 256;
}

void find_color(unsigned char r1, unsigned char g1, unsigned char b1)
{
  double radius = 0;
  double d;
  int i;
  float deltaR;
  float deltaG;
  float deltaB;
  unsigned char rgb[3];

  colorstring[0] = '\0';



loopback:
  d = 0;

  for (i = 0; i < COLOR_NAMES_MAX; i++)
  {
    //Serial.print("index =");
    //Serial.println(i,DEC);
    memcpy_P(rgb, color_data[i], sizeof(rgb));

    deltaR = rgb[0] - r1;
    deltaG = rgb[1] - g1;
    deltaB = rgb[2] - b1;
 		d = (deltaR * deltaR) + (deltaG * deltaG) + (deltaB * deltaB);
    //strcpy_P(colorstring, color_data[i] + 3);
    //Serial.print("Color searched =");  Serial.println(colorstring);
    //Serial.print("Distantce =");Serial.println(d,DEC);
  //Serial.print("Radius =");Serial.println(radius,DEC);
		if (radius >= d)
    {
       strcpy_P(colorstring, color_data[i] + 3);
        
        //Serial.print("Color found =");
       //Serial.println(colorstring);
       return;
    }
  }


//Serial.print("Radius increased to ");Serial.println(radius,DEC);
  radius=radius + 50;
  goto loopback;

}




// This function extracts the hue, saturation, and luminance from "color" 
// and places these values in h, s, and l respectively.
void RGBtoHSL(int r, int g, int b)
{

	double r_percent = ((double)r) / 255;
	double g_percent = ((double)g) / 255;
	double b_percent = ((double)b) / 255;

	double max_color = 0;
	if ((r_percent >= g_percent) && (r_percent >= b_percent))
		max_color = r_percent;
	if ((g_percent >= r_percent) && (g_percent >= b_percent))
		max_color = g_percent;
	if ((b_percent >= r_percent) && (b_percent >= g_percent))
		max_color = b_percent;

	double min_color = 0;
	if ((r_percent <= g_percent) && (r_percent <= b_percent))
		min_color = r_percent;
	if ((g_percent <= r_percent) && (g_percent <= b_percent))
		min_color = g_percent;
	if ((b_percent <= r_percent) && (b_percent <= g_percent))
		min_color = b_percent;

	double L = 0;
	double S = 0;
	double H = 0;

	L = (max_color + min_color) / 2;

	if (max_color == min_color)
	{
		S = 0;
		H = 0;
	}
	else
	{
		if (L < .50)
		{
			S = (max_color - min_color) / (max_color + min_color);
		}
		else
		{
			S = (max_color - min_color) / (2 - max_color - min_color);
		}
		if (max_color == r_percent)
		{
			H = (g_percent - b_percent) / (max_color - min_color);
		}
		if (max_color == g_percent)
		{
			H = 2 + (b_percent - r_percent) / (max_color - min_color);
		}
		if (max_color == b_percent)
		{
			H = 4 + (r_percent - g_percent) / (max_color - min_color);
		}
	}
	s = (unsigned int)(S * 100);
	l = (unsigned int)(L * 100);
	H = H * 60;
	if (H < 0)
		H += 360;
	h = (unsigned int)H;

}

void getshade(void)
{

	//Luma
	if (l >= 60) { strcpy(shadestring, "Light "); }
	if (l >= 75) { strcpy(shadestring, "Very Light "); }
	if (l <= 40) { strcpy(shadestring, "Dark "); }
	if (l <= 20) { strcpy(shadestring, "Very Dark "); }

	//colors

	if (h < 15 || h >= 345) { strcat(shadestring, "Red"); }
	if (h >= 15 && h < 45)
	{
		if (l > 45) { strcat(shadestring, "Orange"); }
		else { strcat(shadestring, "Brown"); }
	}
	if (h >= 45 && h < 75) { strcat(shadestring, "Yellow"); }
	if (h >= 75 && h < 105) { strcat(shadestring, "Lime Green"); }
	if (h >= 105 && h < 135) { strcat(shadestring, "Green"); }
	if (h >= 135 && h < 165) { strcat(shadestring, "Spring Green"); }
	if (h >= 165 && h < 195) { strcat(shadestring, "Cyan"); }
	if (h >= 195 && h < 225) { strcat(shadestring, "Azure"); }
	if (h >= 225 && h < 255) { strcat(shadestring, "Blue"); }
	if (h >= 255 && h < 285) { strcat(shadestring, "Purple"); }
	if (h >= 285 && h < 315) { strcat(shadestring, "Pink"); }
	if (h >= 315 && h < 345) { strcat(shadestring, "Rose"); }

	//Saturation
	if (s <= 10) { strcpy(shadestring, "Grey"); }
	if (l >= 90) { strcpy(shadestring, "White"); }
	if (l <= 10) { strcpy(shadestring, "Black"); }
}

void setspeed(void)
{
    //set Speech speed
  if (CircuitPlayground.slideSwitch() == false)
    {Serial1.println("W200"); delay(50);}
  else
    {Serial1.println("W400"); delay(50);}
}
