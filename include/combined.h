const unsigned short sharedPal[48] __attribute__((aligned(4)))=
{
	0x0000,0x000B,0x25F7,0x0485,0x2D6B,0x4E73,0x1DB4,0x3EDF,
	0x194C,0x0973,0x10C8,0x367C,0x2E3A,0x3DEF,0x110B,0x154F,
	0x1971,0x3A9D,0x5B3F,0x21D6,0x14A5,0x35AD,0x0CEA,0x25F9,
	0x1D93,0x110D,0x14B1,0x294A,0x4AFF,0x08A7,0x21B5,0x325B,
	0x0C6F,0x3EBE,0x2E9F,0x1950,0x08A6,0x3213,0x2A19,0x39CE,
	0x152E,0x4EFF,0x0CC9,0x5294,0x5F5F,0x42DF,0x0851,0x1884,
};

const unsigned int tryenemyTiles[128] __attribute__((aligned(4)))=
{
	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
	0x00000000,0x2E2E2E2E,0x00000000,0x2E2E2E2E,0x2E2E0000,0x2E2E2E2E,0x2E2E2E00,0x2E2E2E2E,
	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00002E00,0x00000000,
	0x2E2E2E2E,0x00000000,0x2E2E2E2E,0x0000002E,0x2E2E2E2E,0x00002E2E,0x2E2E2E2E,0x00002E2E,
	0x2E2E2E00,0x2E2E2E2E,0x2E2E2E00,0x2E2E2E2E,0x2E2E2E00,0x2E2E2E2E,0x2E2E0000,0x2E2E2E2E,
	0x2E2E0000,0x2E2E2E2E,0x2E000000,0x2E2E2E2E,0x00000000,0x2E2E2E2E,0x00000000,0x2E2E0000,
	0x2E2E2E2E,0x002E2E2E,0x2E2E2E2E,0x002E2E2E,0x2E2E2E2E,0x002E2E2E,0x2E2E2E2E,0x002E2E2E,
	0x2E2E2E2E,0x002E2E2E,0x2E2E2E2E,0x002E2E2E,0x2E2E2E2E,0x002E2E2E,0x2E2E2E2E,0x0000002E,

	0x00000000,0x0000002E,0x2E000000,0x2E2E2E2E,0x2E000000,0x2E2E2E2E,0x2E2E0000,0x2E2E2E00,
	0x2E2E2E00,0x2E2E2E00,0x2E2E2E00,0x2E2E2E00,0x002E2E00,0x2E2E2E00,0x002E0000,0x2E2E2E00,
	0x00000000,0x00000000,0x2E2E2E2E,0x0000002E,0x2E2E2E2E,0x00002E2E,0x2E2E2E2E,0x00002E2E,
	0x2E2E2E2E,0x00002E2E,0x002E2E2E,0x002E2E00,0x2E2E2E2E,0x002E2E00,0x2E2E2E2E,0x002E0000,
	0x00000000,0x2E2E2E00,0x00000000,0x2E2E2E2E,0x00000000,0x2E2E2E2E,0x002F0000,0x2E2E2E2E,
	0x2E2F0000,0x002E2E2E,0x2E2F0000,0x00002E2E,0x00000000,0x00002E2E,0x00000000,0x00000000,
	0x2E2E2E2E,0x0000002E,0x2E2E2E2E,0x00002E2E,0x2E2E2E00,0x00002E2E,0x2E2E0000,0x00002E2E,
	0x2E2E0000,0x00002E2E,0x2E2E0000,0x00002E2E,0x2E000000,0x0000002E,0x00000000,0x00000000,
};

const unsigned int avatarTiles[2048] __attribute__((aligned(4)))=
{
	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
	0x00000000,0x00000000,0x00000000,0x24240000,0x00000000,0x24240000,0x00000000,0x0E0E2424,
	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x2A2A0000,0x0E0E0E0E,
	0x2A2A0000,0x0E0E0E0E,0x16160E0E,0x10100F0F,0x16160E0E,0x10100F0F,0x10102828,0x02021E1E,
	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x19190E0E,0x28282828,
	0x19190E0E,0x28282828,0x02021E1E,0x26262626,0x02021E1E,0x26262626,0x26261717,0x13130202,

	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x28282828,0x19192828,
	0x28282828,0x19192828,0x02022626,0x18181E1E,0x02022626,0x18181E1E,0x18181818,0x10101818,
	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x0E0E0E0E,0x00002A2A,
	0x0E0E0E0E,0x00002A2A,0x0E0E2828,0x0E0E1616,0x0E0E2828,0x0E0E1616,0x28281010,0x16162828,
	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
	0x00000000,0x00000000,0x00002424,0x00000000,0x00002424,0x00000000,0x24242A2A,0x00000000,
	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,

	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
	0x00000000,0x0E0E2424,0x00000000,0x28282424,0x00000000,0x28282424,0x03030000,0x0E0E1D1D,
	0x03030000,0x0E0E1D1D,0x03030000,0x2A2A1D1D,0x03030000,0x2A2A1D1D,0x03030000,0x2A2A2A2A,
	0x10102828,0x02021E1E,0x28282323,0x18181010,0x28282323,0x18181010,0x0E0E2828,0x18181010,
	0x0E0E2828,0x18181010,0x0E0E1616,0x16161010,0x0E0E1616,0x16161010,0x28282828,0x10101616,
	0x26261717,0x13130202,0x23231313,0x10101E1E,0x23231313,0x10101E1E,0x10101010,0x10101010,
	0x10101010,0x10101010,0x19191818,0x10101919,0x19191818,0x10101919,0x19191616,0x19192828,

	0x18181818,0x10101818,0x28280606,0x28282828,0x28280606,0x28282828,0x10102A2A,0x2A2A0E0E,
	0x10102A2A,0x2A2A0E0E,0x2A2A1919,0x2A2A1919,0x2A2A1919,0x2A2A1919,0x10101919,0x10101010,
	0x28281010,0x16162828,0x0E0E2828,0x24241616,0x0E0E2828,0x24241616,0x2A2A0E0E,0x03032424,
	0x2A2A0E0E,0x03032424,0x0E0E1D1D,0x24240303,0x0E0E1D1D,0x24240303,0x23232323,0x2A2A1919,
	0x24242A2A,0x00000000,0x03032424,0x00000000,0x03032424,0x00000000,0x03030303,0x00000303,
	0x03030303,0x00000303,0x1D1D2424,0x00000303,0x1D1D2424,0x00000303,0x2A2A1D1D,0x00000303,
	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,

	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
	0x03030000,0x2A2A2A2A,0x03030000,0x16162A2A,0x03030000,0x16162A2A,0x03030000,0x0E0E2A2A,
	0x03030000,0x0E0E2A2A,0x03030000,0x28282A2A,0x03030000,0x28282A2A,0x03030000,0x28282A2A,
	0x28282828,0x10101616,0x10102828,0x16162828,0x10102828,0x16162828,0x1E1E1010,0x06061313,
	0x1E1E1010,0x06061313,0x26261818,0x17171717,0x26261818,0x17171717,0x26261818,0x0B0B1111,
	0x19191616,0x19192828,0x16160606,0x10102828,0x16160606,0x10102828,0x13130606,0x13131313,
	0x13130606,0x13131313,0x06061313,0x1E1E1E1E,0x06061313,0x1E1E1E1E,0x02022626,0x10100606,

	0x10101919,0x10101010,0x13130606,0x06061818,0x13130606,0x06061818,0x13131313,0x06061313,
	0x13131313,0x06061313,0x1E1E1E1E,0x13130606,0x1E1E1E1E,0x13130606,0x06061010,0x26260202,
	0x23232323,0x2A2A1919,0x10101010,0x19191010,0x10101010,0x19191010,0x13130606,0x10101E1E,
	0x13130606,0x10101E1E,0x17171717,0x18182626,0x17171717,0x18182626,0x11110B0B,0x18182626,
	0x2A2A1D1D,0x00000303,0x2A2A2A2A,0x00000303,0x2A2A2A2A,0x00000303,0x2A2A1616,0x00000303,
	0x2A2A1616,0x00000303,0x2A2A0E0E,0x00000303,0x2A2A0E0E,0x00000303,0x2A2A2828,0x00000303,
	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,

	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
	0x03030000,0x28282A2A,0x03030000,0x28282A2A,0x03030000,0x28282A2A,0x19191313,0x28282A2A,
	0x19191313,0x28282A2A,0x19191313,0x13130A0A,0x19191313,0x13130A0A,0x19191010,0x13130808,
	0x26261818,0x0B0B1111,0x0B0B1313,0x1C1C1C1C,0x0B0B1313,0x1C1C1C1C,0x1D1D1D1D,0x06061616,
	0x1D1D1D1D,0x06061616,0x0E0E2323,0x1D1D1D1D,0x0E0E2323,0x1D1D1D1D,0x0D0D2828,0x15150505,
	0x02022626,0x10100606,0x0B0B0B0B,0x0C0C2626,0x0B0B0B0B,0x0C0C2626,0x1C1C1F1F,0x21210202,
	0x1C1C1F1F,0x21210202,0x00001D1D,0x1E1E0E0E,0x00001D1D,0x1E1E0E0E,0x00000000,0x16162A2A,

	0x06061010,0x26260202,0x26260C0C,0x0B0B0B0B,0x26260C0C,0x0B0B0B0B,0x02022121,0x18181C1C,
	0x02022121,0x18181C1C,0x0E0E1E1E,0x00000000,0x0E0E1E1E,0x00000000,0x2A2A1616,0x1B1B0000,
	0x11110B0B,0x18182626,0x16161818,0x1D1D0000,0x16161818,0x1D1D0000,0x1D1D0000,0x23232828,
	0x1D1D0000,0x23232828,0x1D1D0000,0x13130E0E,0x1D1D0000,0x13130E0E,0x15150505,0x28280000,
	0x2A2A2828,0x00000303,0x2A2A2828,0x00000303,0x2A2A2828,0x00000303,0x2A2A2828,0x13131919,
	0x2A2A2828,0x13131919,0x0A0A1010,0x13131919,0x0A0A1010,0x13131919,0x08081313,0x10101919,
	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,

	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
	0x19191010,0x13130808,0x0E0E1919,0x13132323,0x0E0E1919,0x13132323,0x0E0E2323,0x0C0C2323,
	0x0E0E2323,0x0C0C2323,0x0E0E1010,0x26261010,0x0E0E1010,0x26261010,0x0E0E0000,0x06062323,
	0x0D0D2828,0x15150505,0x1E1E1010,0x1E1E1111,0x1E1E1010,0x1E1E1111,0x02020C0C,0x10101E1E,
	0x02020C0C,0x10101E1E,0x11111F1F,0x17171F1F,0x11111F1F,0x17171F1F,0x02021E1E,0x11110C0C,
	0x00000000,0x16162A2A,0x0E0E1919,0x26261010,0x0E0E1919,0x26261010,0x26261E1E,0x21211E1E,
	0x26261E1E,0x21211E1E,0x1C1C0B0B,0x1C1C0B0B,0x1C1C0B0B,0x1C1C0B0B,0x1F1F2D2D,0x07070C0C,

	0x2A2A1616,0x1B1B0000,0x10102626,0x19190E0E,0x10102626,0x19190E0E,0x1E1E2121,0x1E1E2626,
	0x1E1E2121,0x1E1E2626,0x0B0B1C1C,0x0B0B1C1C,0x0B0B1C1C,0x0B0B1C1C,0x0C0C2C2C,0x2D2D1F1F,
	0x15150505,0x28280000,0x11111E1E,0x10101E1E,0x11111E1E,0x10101E1E,0x1E1E1010,0x0C0C0202,
	0x1E1E1010,0x0C0C0202,0x1F1F1717,0x1F1F1111,0x1F1F1717,0x1F1F1111,0x0C0C1111,0x1E1E0202,
	0x08081313,0x10101919,0x23231313,0x19190E0E,0x23231313,0x19190E0E,0x23230C0C,0x23230E0E,
	0x23230C0C,0x23230E0E,0x10102626,0x10100E0E,0x10102626,0x10100E0E,0x23230606,0x00000E0E,
	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,

	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
	0x0E0E0000,0x06062323,0x0E0E0000,0x18182828,0x0E0E0000,0x18182828,0x00000000,0x13132828,
	0x00000000,0x13132828,0x00000000,0x17170E0E,0x00000000,0x17170E0E,0x00000000,0x1E1E1616,
	0x02021E1E,0x11110C0C,0x02020606,0x29291111,0x02020606,0x29291111,0x0C0C1818,0x0B0B1C1C,
	0x0C0C1818,0x0B0B1C1C,0x0B0B1818,0x02022121,0x0B0B1818,0x02022121,0x0C0C0606,0x26260B0B,
	0x1F1F2D2D,0x07070C0C,0x1E1E0C0C,0x25251818,0x1E1E0C0C,0x25251818,0x16160606,0x23232828,
	0x16160606,0x23232828,0x1F1F2626,0x06060202,0x1F1F2626,0x06060202,0x21210C0C,0x0C0C2929,

	0x0C0C2C2C,0x2D2D1F1F,0x18182525,0x0C0C1E1E,0x18182525,0x0C0C1E1E,0x28282323,0x06061616,
	0x28282323,0x06061616,0x02020606,0x26261F1F,0x02020606,0x26261F1F,0x29290C0C,0x0C0C2121,
	0x0C0C1111,0x1E1E0202,0x11112929,0x06060202,0x11112929,0x06060202,0x1C1C0B0B,0x18180C0C,
	0x1C1C0B0B,0x18180C0C,0x21210202,0x18180B0B,0x21210202,0x18180B0B,0x0B0B2626,0x06060C0C,
	0x23230606,0x00000E0E,0x28281818,0x00000E0E,0x28281818,0x00000E0E,0x28281313,0x00000000,
	0x28281313,0x00000000,0x0E0E1717,0x00000000,0x0E0E1717,0x00000000,0x16161E1E,0x00000000,
	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,

	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
	0x00000000,0x1E1E1616,0x00000000,0x23230000,0x00000000,0x23230000,0x00000000,0x16160000,
	0x00000000,0x16160000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
	0x0C0C0606,0x26260B0B,0x17171E1E,0x10100C0C,0x17171E1E,0x10100C0C,0x13131010,0x17171717,
	0x13131010,0x17171717,0x18181919,0x1F1F2626,0x18181919,0x1F1F2626,0x19190000,0x26260606,
	0x21210C0C,0x0C0C2929,0x09092828,0x09090909,0x09092828,0x09090909,0x0C0C1717,0x22220B0B,
	0x0C0C1717,0x22220B0B,0x1E1E1717,0x0F0F1010,0x1E1E1717,0x0F0F1010,0x17171F1F,0x0B0B1717,

	0x29290C0C,0x0C0C2121,0x09090909,0x28280909,0x09090909,0x28280909,0x0B0B2222,0x17170C0C,
	0x0B0B2222,0x17170C0C,0x10100F0F,0x17171E1E,0x10100F0F,0x17171E1E,0x17170B0B,0x1F1F1717,
	0x0B0B2626,0x06060C0C,0x0C0C1010,0x1E1E1717,0x0C0C1010,0x1E1E1717,0x17171717,0x10101313,
	0x17171717,0x10101313,0x26261F1F,0x19191818,0x26261F1F,0x19191818,0x06062626,0x00001919,
	0x16161E1E,0x00000000,0x00002323,0x00000000,0x00002323,0x00000000,0x00001616,0x00000000,
	0x00001616,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,

	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
	0x19190000,0x26260606,0x00000000,0x23231616,0x00000000,0x23231616,0x00000000,0x00000000,
	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
	0x17171F1F,0x0B0B1717,0x0C0C1313,0x29290B0B,0x0C0C1313,0x29290B0B,0x10101919,0x06060606,
	0x10101919,0x06060606,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,

	0x17170B0B,0x1F1F1717,0x0B0B2929,0x13130C0C,0x0B0B2929,0x13130C0C,0x06060606,0x19191010,
	0x06060606,0x19191010,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
	0x06062626,0x00001919,0x16162323,0x00000000,0x16162323,0x00000000,0x00000000,0x00000000,
	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,

	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x24000000,
	0x00000000,0x24000000,0x00000000,0x0E242400,0x00000000,0x0E242400,0x00000000,0x28242400,
	0x00000000,0x00000000,0x2A000000,0x0E0E0E2A,0x2A000000,0x0E0E0E2A,0x160E0E24,0x190E0E16,
	0x160E0E24,0x190E0E16,0x1028280E,0x02181810,0x1028280E,0x02181810,0x28232328,0x18101028,
	0x00000000,0x00000000,0x190E0E0E,0x28282819,0x190E0E0E,0x28282819,0x02101019,0x26131302,
	0x02101019,0x26131302,0x26171702,0x13060626,0x26171702,0x13060626,0x23131318,0x101E1E23,

	0x00000000,0x00000000,0x28282828,0x19282828,0x28282828,0x19282828,0x13262626,0x181E1E13,
	0x13262626,0x181E1E13,0x18181813,0x10181818,0x18181813,0x10181818,0x28060610,0x28282828,
	0x00000000,0x00000000,0x0E0E0E19,0x002A2A0E,0x0E0E0E19,0x002A2A0E,0x0E282818,0x0E16160E,
	0x0E282818,0x0E16160E,0x28101010,0x16282828,0x28101010,0x16282828,0x0E282828,0x2416160E,
	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x0024240E,0x00000000,
	0x0024240E,0x00000000,0x242A2A16,0x00000024,0x242A2A16,0x00000024,0x03242424,0x00000003,
	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,

	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
	0x00000000,0x28242400,0x03000000,0x0E1D1D03,0x03000000,0x0E1D1D03,0x03000000,0x2A1D1D03,
	0x03000000,0x2A1D1D03,0x03000000,0x2A2A2A03,0x03000000,0x2A2A2A03,0x03000000,0x162A2A03,
	0x28232328,0x18101028,0x0E28280E,0x1810100E,0x0E28280E,0x1810100E,0x0E16162A,0x1610100E,
	0x0E16162A,0x1610100E,0x2828282A,0x10161628,0x2828282A,0x10161628,0x10282816,0x16282810,
	0x23131318,0x101E1E23,0x10101018,0x10101010,0x10101018,0x10101010,0x19181816,0x10191919,
	0x19181816,0x10191919,0x19161610,0x19282819,0x19161610,0x19282819,0x16060616,0x10282816,

	0x28060610,0x28282828,0x102A2A10,0x2A0E0E10,0x102A2A10,0x2A0E0E10,0x2A191910,0x2A19192A,
	0x2A191910,0x2A19192A,0x10191919,0x10101010,0x10191919,0x10101010,0x13060610,0x06181813,
	0x0E282828,0x2416160E,0x2A0E0E2A,0x0324242A,0x2A0E0E2A,0x0324242A,0x0E1D1D2A,0x2403030E,
	0x0E1D1D2A,0x2403030E,0x23232310,0x2A191923,0x23232310,0x2A191923,0x10101006,0x19101010,
	0x03242424,0x00000003,0x03030303,0x00030303,0x03030303,0x00030303,0x1D242424,0x0003031D,
	0x1D242424,0x0003031D,0x2A1D1D2A,0x0003032A,0x2A1D1D2A,0x0003032A,0x2A2A2A19,0x0003032A,
	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,

	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
	0x03000000,0x162A2A03,0x03000000,0x0E2A2A03,0x03000000,0x0E2A2A03,0x03000000,0x282A2A03,
	0x03000000,0x282A2A03,0x03000000,0x282A2A03,0x03000000,0x282A2A03,0x03000000,0x282A2A03,
	0x10282816,0x16282810,0x1E10100E,0x0613131E,0x1E10100E,0x0613131E,0x26181828,0x17171726,
	0x26181828,0x17171726,0x26181828,0x0B111126,0x26181828,0x0B111126,0x0B131328,0x1C1C1C0B,
	0x16060616,0x10282816,0x13060606,0x0B0C0C13,0x13060606,0x0B0C0C13,0x0C131317,0x1E1E1E0C,
	0x0C131317,0x1E1E1E0C,0x0226260B,0x0C060602,0x0226260B,0x0C060602,0x0C0B0B1C,0x0C13130C,

	0x13060610,0x06181813,0x0C0B0B0B,0x0C13130C,0x0C0B0B0B,0x0C13130C,0x1E1E1E1E,0x130C0C1E,
	0x1E1E1E1E,0x130C0C1E,0x060B0B0C,0x18020206,0x060B0B0C,0x18020206,0x1E0C0C0C,0x121E1E1E,
	0x10101006,0x19101010,0x1306060C,0x101E1E13,0x1306060C,0x101E1E13,0x18181813,0x18262618,
	0x18181813,0x18262618,0x110B0B18,0x18262611,0x110B0B18,0x18262611,0x1C111112,0x130B0B1C,
	0x2A2A2A19,0x0003032A,0x2A161610,0x0003032A,0x2A161610,0x0003032A,0x2A0E0E18,0x0003032A,
	0x2A0E0E18,0x0003032A,0x2A282818,0x0003032A,0x2A282818,0x0003032A,0x2A282813,0x0003032A,
	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,

	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
	0x03000000,0x282A2A03,0x19131300,0x102A2A19,0x19131300,0x102A2A19,0x19131300,0x280A0A19,
	0x19131300,0x280A0A19,0x19101000,0x19232319,0x19101000,0x19232319,0x0E191900,0x2323230E,
	0x0B131328,0x1C1C1C0B,0x19191910,0x26232319,0x19191910,0x26232319,0x1E1F1F28,0x1D10101E,
	0x1E1F1F28,0x1D10101E,0x00101019,0x2B272700,0x00101019,0x2B272700,0x27161623,0x002A2A27,
	0x0C0B0B1C,0x0C13130C,0x122D2D26,0x130C0C12,0x122D2D26,0x130C0C12,0x2319191D,0x0B1F1F23,
	0x2319191D,0x0B1F1F23,0x2A1D1D2B,0x1F10102A,0x2A1D1D2B,0x1F10102A,0x002B2B00,0x06161600,

	0x1E0C0C0C,0x121E1E1E,0x26131313,0x1F121226,0x26131313,0x1F121226,0x0B26260B,0x1913130B,
	0x0B26260B,0x1913130B,0x1002021F,0x1D2A2A10,0x1002021F,0x1D2A2A10,0x16212106,0x27000016,
	0x1C111112,0x130B0B1C,0x1606061F,0x19191916,0x1606061F,0x19191916,0x101D1D19,0x1F1E1E10,
	0x101D1D19,0x1F1E1E10,0x2B27271D,0x1000002B,0x2B27271D,0x1000002B,0x2A000027,0x162B2B2A,
	0x2A282813,0x0003032A,0x2A101019,0x1319192A,0x2A101019,0x1319192A,0x0A28281F,0x1319190A,
	0x0A28281F,0x1319190A,0x23191910,0x10191923,0x23191910,0x10191923,0x23232316,0x190E0E23,
	0x00000000,0x00000000,0x00000013,0x00000000,0x00000013,0x00000000,0x00000013,0x00000000,
	0x00000013,0x00000000,0x00000010,0x00000000,0x00000010,0x00000000,0x00000019,0x00000000,

	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
	0x0E191900,0x2323230E,0x0E232300,0x2623230E,0x0E232300,0x2623230E,0x0E101000,0x2610100E,
	0x0E101000,0x2610100E,0x0E000000,0x0210100E,0x0E000000,0x0210100E,0x0E000000,0x1010100E,
	0x27161623,0x002A2A27,0x0E131326,0x0404040E,0x0E131326,0x0404040E,0x130B0B26,0x230E0E13,
	0x130B0B26,0x230E0E13,0x210B0B02,0x1C212121,0x210B0B02,0x1C212121,0x1E131310,0x260B0B1E,
	0x002B2B00,0x06161600,0x21262604,0x02101021,0x21262604,0x02101021,0x1C262623,0x260C0C1C,
	0x1C262623,0x260C0C1C,0x2111111C,0x070C0C21,0x2111111C,0x070C0C21,0x1E101026,0x2518181E,

	0x16212106,0x27000016,0x100B0B02,0x26212110,0x100B0B02,0x26212110,0x0C070726,0x261C1C0C,
	0x0C070726,0x261C1C0C,0x0C2C2C07,0x2121210C,0x0C2C2C07,0x2121210C,0x18252525,0x101E1E18,
	0x2A000027,0x162B2B2A,0x04040426,0x130E0E04,0x04040426,0x130E0E04,0x0E232326,0x0B13130E,
	0x0E232326,0x0B13130E,0x1C111121,0x0B21211C,0x1C111121,0x0B21211C,0x0B262610,0x021E1E0B,
	0x23232316,0x190E0E23,0x23262613,0x230E0E23,0x23262613,0x230E0E23,0x1026260B,0x100E0E10,
	0x1026260B,0x100E0E10,0x1002020B,0x000E0E10,0x1002020B,0x000E0E10,0x10101002,0x000E0E10,
	0x00000019,0x00000000,0x00000023,0x00000000,0x00000023,0x00000000,0x00000010,0x00000000,
	0x00000010,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,

	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
	0x0E000000,0x1010100E,0x0E000000,0x0F06060E,0x0E000000,0x0F06060E,0x00000000,0x10101000,
	0x00000000,0x10101000,0x00000000,0x060F0F00,0x00000000,0x060F0F00,0x00000000,0x10000000,
	0x1E131310,0x260B0B1E,0x060F0F0F,0x100B0B06,0x060F0F0F,0x100B0B06,0x06232310,0x190C0C06,
	0x06232310,0x190C0C06,0x060F0F06,0x28262606,0x060F0F06,0x28262606,0x180F0F10,0x18020218,
	0x1E101026,0x2518181E,0x16232310,0x23282816,0x16232310,0x23282816,0x0C131319,0x1918180C,
	0x0C131319,0x1918180C,0x21131328,0x0C0C0C21,0x21131328,0x0C0C0C21,0x1E0C0C18,0x2828281E,

	0x18252525,0x101E1E18,0x28232323,0x23161628,0x28232323,0x23161628,0x18191919,0x130C0C18,
	0x18191919,0x130C0C18,0x0C0C0C0C,0x1321210C,0x0C0C0C0C,0x1321210C,0x28282828,0x0C1E1E28,
	0x0B262610,0x021E1E0B,0x0B101023,0x0F06060B,0x0B101023,0x0F06060B,0x0C191913,0x2306060C,
	0x0C191913,0x2306060C,0x26282813,0x0F060626,0x26282813,0x0F060626,0x0218180C,0x0F181802,
	0x10101002,0x000E0E10,0x060F0F0F,0x000E0E06,0x060F0F0F,0x000E0E06,0x10060623,0x00000010,
	0x10060623,0x00000010,0x0F02020F,0x0000000F,0x0F02020F,0x0000000F,0x0006060F,0x00000000,
	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,

	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
	0x00000000,0x10000000,0x00000000,0x23000000,0x00000000,0x23000000,0x00000000,0x28000000,
	0x00000000,0x28000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
	0x180F0F10,0x18020218,0x230F0F23,0x18020223,0x230F0F23,0x18020223,0x0F0F0F28,0x1E06060F,
	0x0F0F0F28,0x1E06060F,0x280F0F00,0x02101028,0x280F0F00,0x02101028,0x28282800,0x26232328,
	0x1E0C0C18,0x2828281E,0x14131318,0x27040414,0x14131318,0x27040414,0x0018181E,0x00000000,
	0x0018181E,0x00000000,0x00232302,0x00010100,0x00232302,0x00010100,0x04060626,0x201A1A04,

	0x28282828,0x0C1E1E28,0x04272727,0x13141404,0x04272727,0x13141404,0x00000000,0x18000000,
	0x00000000,0x18000000,0x01000000,0x23000001,0x01000000,0x23000001,0x1A202020,0x0604041A,
	0x0218180C,0x0F181802,0x02181813,0x0F0F0F02,0x02181813,0x0F0F0F02,0x061E1E18,0x0F282806,
	0x061E1E18,0x0F282806,0x10020223,0x0F282810,0x10020223,0x0F282810,0x23262606,0x28282823,
	0x0006060F,0x00000000,0x0023230F,0x00000000,0x0023230F,0x00000000,0x0028280F,0x00000000,
	0x0028280F,0x00000000,0x0000000F,0x00000000,0x0000000F,0x00000000,0x00000028,0x00000000,
	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,

	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
	0x28282800,0x26232328,0x28000000,0x130F0F28,0x28000000,0x130F0F28,0x00000000,0x10282800,
	0x00000000,0x10282800,0x00000000,0x28000000,0x00000000,0x28000000,0x00000000,0x00000000,
	0x04060626,0x201A1A04,0x101E1E13,0x27040410,0x101E1E13,0x27040410,0x1E1E1E10,0x0F10101E,
	0x1E1E1E10,0x0F10101E,0x17181828,0x29111117,0x17181828,0x29111117,0x00000000,0x00000000,

	0x1A202020,0x0604041A,0x04272727,0x1E101004,0x04272727,0x1E101004,0x100F0F0F,0x1E1E1E10,
	0x100F0F0F,0x1E1E1E10,0x11292929,0x18171711,0x11292929,0x18171711,0x00000000,0x00000000,
	0x23262606,0x28282823,0x0F13131E,0x0028280F,0x0F13131E,0x0028280F,0x2810101E,0x00000028,
	0x2810101E,0x00000028,0x00282818,0x00000000,0x00282818,0x00000000,0x00000000,0x00000000,
	0x00000028,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
};