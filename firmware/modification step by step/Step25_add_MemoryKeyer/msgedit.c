//
//  Edit Memory Keyer message for SDR-3
//
//  This program is free software; you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation; either version 2 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program; if not, write to the Free Software
//  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//
// (C) JI1UDD 2019

//--------------------------------------------------------------------
// ���b�Z�[�W (�ő�47����)
//--------------------------------------------------------------------
static char keyer_message[4][48] = {
  "CQ CQ CQ DE JA1QRZ JA1QRZ JA1QRZ PSE K",         // ���b�Z�[�W 0 �����l
  "DE JA1QRZ K",                                    // ���b�Z�[�W 1 �����l
  "QSL UR 5NN BK",                                  // ���b�Z�[�W 2 �����l
  "TNX FB QSO CU AGN 73 TU :"                       // ���b�Z�[�W 3 �����l
};
//          1         2         3         4      4
// 12345678901234567890123456789012345678901234567

//--------------------------------------------------------------------

static int m_msg_edit_mode = 0 ;    // ���b�Z�[�W�G�f�B�b�g���[�h
static int m_num ;                  // �G�f�B�b�g�Ώۃ������ԍ�
static int m_column ;               // �G�f�B�b�g�Ώە����ʒu
static int m_dsppos ;               // �G�f�B�b�g�\���J�n�ʒu

void m_edit_msg_disp( void ) ;
char * m_strcopy( char *src, char *dest, int n, int m ) ;

//--------------------------------------------------------------------
// CW���[�h���ۂ����`�F�b�N
//--------------------------------------------------------------------
int chk_cw_mode( void ) {
  return (( mod==3)||( mod==4 )) ;   // CWL or CWU
}

//--------------------------------------------------------------------
// ���b�Z�[�W�G�f�B�b�g���[�h�ɓ���
//--------------------------------------------------------------------
void m_enter_edit_mode( int num ) {
  char *ptr ;
  m_msg_edit_mode = 1 ;
  radio_buttons[N_BUTTON_DENOISE].status = 0;     // DENOISE �s�g�p
  radio_buttons[N_BUTTON_STEREO].status = 0;      // STEREO �s�g�p
  radio_buttons[N_BUTTON_FSTEP].status = 0;       // F.Step �s�g�p
  radio_buttons[N_BUTTON_MEDIT].status = 7;       // MEdit �g�p�����\��
  m_column = 0 ;
  m_dsppos = 0 ;
  m_edit_msg_disp() ;
}

//--------------------------------------------------------------------
// ���b�Z�[�W�G�f�B�b�g���[�h���甲����
//--------------------------------------------------------------------
void m_exit_edit_mode( void ) {
  m_msg_edit_mode = 0 ;
  radio_buttons[N_BUTTON_DENOISE].status = 7;     // DENOISE �g�p�����\��
  radio_buttons[N_BUTTON_STEREO].status = 7;      // STEREO �g�p�����\��
  radio_buttons[N_BUTTON_FSTEP].status = 7;       // F.Step �g�p�����\��
  radio_buttons[N_BUTTON_MEDIT].status = 0;       // Message Edit �s�g�p
  gui_update_all();
  spectrum_update();
}

//--------------------------------------------------------------------
// ���b�Z�[�W�G�f�B�^�\��    style 76543210
//   �J�[�\���t���������\��    bit |||+++++--- cursor�ʒu (0�`25)
//   style��`��ύX���Ď���  ��` ||+--------  1: �J�[�\���t�������\��
//                                 ++--------- 00: rect
//--------------------------------------------------------------------
void m_edit_msg_disp( void ) {
  m_strcopy( keyer_message[m_num], str_edit_msg, m_dsppos, 26 );  // ���b�Z�[�W��\��(Max 26����)
  radio_buttons[N_BUTTON_MEDIT].style = ( 0x20 | ( m_column> 25 ? 25 : m_column )); // cursor�ʒu�ݒ�
  gui_update_button( N_BUTTON_MEDIT );
}

//--------------------------------------------------------------------
// ���[�^���[�G���R�[�_�Ń��b�Z�[�W������I��
//--------------------------------------------------------------------
void m_sel_char( int rot ) {
  char c ;

  c = ( keyer_message[m_num][m_column] + rot ) ;
  if  ( c > 0x5A ) { 
    c = c - 0x2C ;
  } else if ( c < 0x2F ) {
    c = c + 0x2C ;
  }
  keyer_message[m_num][m_column] = c ;
  m_edit_msg_disp() ;
}

//--------------------------------------------------------------------
// ���[�^���[�G���R�[�_�ŃG�f�B�b�g�Ώە����ʒu���ړ�
//--------------------------------------------------------------------
void m_move_column( int rot ) {
  if ( rot==1 ) {
    if ( m_column < 46 ) {
      m_column++ ;
      if ( keyer_message[m_num][m_column]==0 ) {
        keyer_message[m_num][m_column]=0x20 ;
        keyer_message[m_num][m_column+1]=0 ;
      }
      if ( (m_column - m_dsppos)==26 ) {
        m_dsppos++ ;
      }
    }
  } else if ( rot==-1) {
    if ( m_column > 0 ) {
      m_column-- ;
      if ( m_dsppos > 0 ) {
         m_dsppos-- ;
      }
    }
  }
  m_edit_msg_disp() ;
}

//--------------------------------------------------------------------
// �G�f�B�b�g�Ώۈʒu�ɃX�y�[�X��}��
//--------------------------------------------------------------------
void m_ins_char( void ) {
  int n ;
  if ( m_column < 46 ) {
    n = strlength( keyer_message[m_num] )+1 ;  
    while ( n > m_column ) {
      keyer_message[m_num][n] = keyer_message[m_num][n-1] ;
      n-- ;
    }
    keyer_message[m_num][n]=0x20;
    m_edit_msg_disp() ;
  }
}

//--------------------------------------------------------------------
// �G�f�B�b�g�Ώۈʒu�̕������폜
//--------------------------------------------------------------------
void m_del_char( void ) {
  int n = m_column ;
  if ( keyer_message[m_num][n]!=0 ) {
    while( keyer_message[m_num][n+1] ) {
      keyer_message[m_num][n]=keyer_message[m_num][n+1] ;
      n++ ;
    }
    keyer_message[m_num][n]=0 ;
    m_edit_msg_disp() ;
  }
}

//--------------------------------------------------------------------
// ������R�s�[ n������(0�`) ���� �ő�m������(1�`)
//--------------------------------------------------------------------
char * m_strcopy( char *src, char *dest, int n, int m ) {
  src += n ;
  while( *src && m-- ) {
    *dest++ = *src++;
  }
  *dest = 0;
  return dest;
}
