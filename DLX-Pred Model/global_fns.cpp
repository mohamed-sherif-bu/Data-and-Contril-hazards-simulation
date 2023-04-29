int pow(int base, int exp)
{
  int res=1;
  for (int i=0; i<exp; i++) 
	res *= base;
  return res;
}

float floatFromInt(int v) {
  float res;
  int *p = (int*)(&res);
  *p = v;
  //printf("float<-Int: %d %f.\n", v, res);
  return res;
}

int floatToInt(float d) {
  int *p = (int*)(&d);
  //printf("float->int: %f %d.\n", d, *p);
  return *p;
}

t_reg_args Decode_Register(char *Input_Reg)
{
	t_reg_args new_reg;
	if (Input_Reg[0]=='R')
	  {
    	new_reg.type='R';
        new_reg.number=atoi(Input_Reg+1);
        new_reg.index=0;
          } 
	else if (Input_Reg[0]=='F')
	  {
    	new_reg.type='F';
        new_reg.number=atoi(Input_Reg+1);
        new_reg.index=0;
          }
	else
	  {
    	char temp_str[100];
        strcpy(temp_str,Input_Reg);
        char *str1=strstr(Input_Reg,"(");
        str1[0]='\0';
        new_reg.index=atoi(temp_str);
        char *str2=str1+1;
        if (str2[0]=='R')
	  {new_reg.type='R';}
	else
	  {new_reg.type='F';}
        str2++;
        str2[strlen(str2)-1]='\0';
        new_reg.number=atoi(str2);
         }
    return new_reg;
}

int Decode_DBL(t_dlx_instrn_set Instruction)
{
  if (   Instruction.function == t_dlx_instrn_set::MOVD
	 ||Instruction.function == t_dlx_instrn_set::JAL
	 ||Instruction.function == t_dlx_instrn_set::JALR
	 )
    return 1;
  return 0;
}


int is_a_function(t_dlx_instrn_set Instruction)
{
  if (     Instruction.function == t_dlx_instrn_set::ADD
        || Instruction.function == t_dlx_instrn_set::ADDF
	|| Instruction.function == t_dlx_instrn_set::ADDI
        || Instruction.function == t_dlx_instrn_set::ADDU
	|| Instruction.function == t_dlx_instrn_set::ADDUI
	|| Instruction.function == t_dlx_instrn_set::AND
	|| Instruction.function == t_dlx_instrn_set::ANDI
	|| Instruction.function == t_dlx_instrn_set::BEQZ
	|| Instruction.function == t_dlx_instrn_set::BFPF
	|| Instruction.function == t_dlx_instrn_set::BFPT
	|| Instruction.function == t_dlx_instrn_set::BNEZ
	|| Instruction.function == t_dlx_instrn_set::DIV
	|| Instruction.function == t_dlx_instrn_set::DIVF
	|| Instruction.function == t_dlx_instrn_set::EQF
	|| Instruction.function == t_dlx_instrn_set::GEF
	|| Instruction.function == t_dlx_instrn_set::GTF
	|| Instruction.function == t_dlx_instrn_set::J
	|| Instruction.function == t_dlx_instrn_set::JAL
	|| Instruction.function == t_dlx_instrn_set::JR
	|| Instruction.function == t_dlx_instrn_set::JALR
	|| Instruction.function == t_dlx_instrn_set::LB
	|| Instruction.function == t_dlx_instrn_set::LBU
	|| Instruction.function == t_dlx_instrn_set::LEF
	|| Instruction.function == t_dlx_instrn_set::LF
	|| Instruction.function == t_dlx_instrn_set::LH
	|| Instruction.function == t_dlx_instrn_set::LHI
	|| Instruction.function == t_dlx_instrn_set::LHU
	|| Instruction.function == t_dlx_instrn_set::LTF
	|| Instruction.function == t_dlx_instrn_set::LW
	|| Instruction.function == t_dlx_instrn_set::MOVD
	|| Instruction.function == t_dlx_instrn_set::MOVF
	|| Instruction.function == t_dlx_instrn_set::MOVFP2I
	|| Instruction.function == t_dlx_instrn_set::MOVI2FP
	|| Instruction.function == t_dlx_instrn_set::MULT
	|| Instruction.function == t_dlx_instrn_set::MULTF
	|| Instruction.function == t_dlx_instrn_set::NEF
	|| Instruction.function == t_dlx_instrn_set::NOP
	|| Instruction.function == t_dlx_instrn_set::OR
	|| Instruction.function == t_dlx_instrn_set::ORI
	|| Instruction.function == t_dlx_instrn_set::SB
	|| Instruction.function == t_dlx_instrn_set::SEQ
	|| Instruction.function == t_dlx_instrn_set::SEQI
	|| Instruction.function == t_dlx_instrn_set::SF
	|| Instruction.function == t_dlx_instrn_set::SGE
	|| Instruction.function == t_dlx_instrn_set::SGEI
	|| Instruction.function == t_dlx_instrn_set::SGT
	|| Instruction.function == t_dlx_instrn_set::SGTI
	|| Instruction.function == t_dlx_instrn_set::SH
	|| Instruction.function == t_dlx_instrn_set::SLE
	|| Instruction.function == t_dlx_instrn_set::SLEI
	|| Instruction.function == t_dlx_instrn_set::SLL
	|| Instruction.function == t_dlx_instrn_set::SLLI
	|| Instruction.function == t_dlx_instrn_set::SLT
	|| Instruction.function == t_dlx_instrn_set::SLTI
	|| Instruction.function == t_dlx_instrn_set::SNE
	|| Instruction.function == t_dlx_instrn_set::SNEI
	|| Instruction.function == t_dlx_instrn_set::SPEQ
	|| Instruction.function == t_dlx_instrn_set::SPNE
	|| Instruction.function == t_dlx_instrn_set::SPLT
	|| Instruction.function == t_dlx_instrn_set::SPGT
	|| Instruction.function == t_dlx_instrn_set::SPLE
	|| Instruction.function == t_dlx_instrn_set::SPGE
	|| Instruction.function == t_dlx_instrn_set::SRA
	|| Instruction.function == t_dlx_instrn_set::SRAI
	|| Instruction.function == t_dlx_instrn_set::SRL
	|| Instruction.function == t_dlx_instrn_set::SRLI
	|| Instruction.function == t_dlx_instrn_set::SUB
	|| Instruction.function == t_dlx_instrn_set::SUBI
	|| Instruction.function == t_dlx_instrn_set::SUBU
	|| Instruction.function == t_dlx_instrn_set::SUBUI
	|| Instruction.function == t_dlx_instrn_set::SUBF
	|| Instruction.function == t_dlx_instrn_set::SW
	|| Instruction.function == t_dlx_instrn_set::TRAP
	|| Instruction.function == t_dlx_instrn_set::VOID
	|| Instruction.function == t_dlx_instrn_set::XOR
	|| Instruction.function == t_dlx_instrn_set::XORI
	   )
    return 1;
  return 0;
}
