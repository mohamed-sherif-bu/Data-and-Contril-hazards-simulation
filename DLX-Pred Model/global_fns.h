// Project:	DLX 
// Entity	Global Functions
// File		globals_fns.h
// Date:	26 Sept 2000

class scoreboard;  // Units are declared here to allow forward references
class control_box;    // between them. HASE automatically declares them from
class clock;       // the dlx.edl file, but in sequence, only allowing
class registers;   // backward references.
class memory;
class instr_fetch;
class instr_decode;
class int_exe;
class flt_exe;
class mul_exe;
class div_exe;
class execute;
class mem_access;
class write_back;


int pow(int, int);  // forms exponential without using doubles

float floatFromInt(int v);
int floatToInt(float d);

struct t_reg_args {
  char type;       // Either R or F
  int  number;     // Register number
  int  index;	   // Offset (if any)
};

class t_reg_args Decode_Register(char *Instruction);

int Decode_LOAD(t_dlx_instrn_set Instruction);

int Decode_STORE(t_dlx_instrn_set Instruction);

int Decode_MOVE(t_dlx_instrn_set Instruction);

int Decode_ALU(t_dlx_instrn_set Instruction);

int Decode_ALUI(t_dlx_instrn_set Instruction);

int Decode_ALUP(t_dlx_instrn_set Instruction);

int Decode_JIMM(t_dlx_instrn_set Instruction);

int Decode_JREG(t_dlx_instrn_set Instruction);

int Decode_BRNC(t_dlx_instrn_set Instruction);

int Decode_FLPT(t_dlx_instrn_set Instruction);

int Decode_COMP(t_dlx_instrn_set Instruction);

int Decode_DBL(t_dlx_instrn_set Instruction);

int is_a_function(t_dlx_instrn_set Instruction);





