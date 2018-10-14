# SDR-3 firmware
Modification step by step.

### Step1:
- ��������H�[��HP�Ɍf�ڂ���Ă���p�b�`�̓K�p

### Step2:
- CW���[�h(CW Lower �� CW Upper)��ǉ�
- LCD��ɕ\������Ă�����g�������M���g���ƂȂ�
- PTT�������Ƒ��M�ƂȂ�
- CW�g��ON/OFF���ɑ��֐��͎g�p���Ă��Ȃ�(CW�g�͋}�s�ɗ����オ��/�����肷��)�B

### Step3:
- CW�L�[�C���O�@�\��ǉ�
- CW key �� PA5 �� �g�p�BR2 �� 3.3k���������B
- PTT �ő��M��Ԃɂ��āAPA5��GND�ɗ��Ƃ���CW�g�̑��M�ƂȂ�B
- CW�g��ON/OFF�͑��֐�(raised cosine)���g�p(CW�g�͊ɂ₩�ɗ����オ��/�����肷��)�B

### Step4:
- iambic�L�[���[�@�\��ǉ�
- Dot key �� PA5 ���A Dash key �� PA6 ���g�p�B R3 �� 3.3k������������
- PA5/PA6��GND�ɗ��Ƃ���Dot/Dash��CW�g�����M����� (PTT�̑���͕s�v)�B
- USB�[�q(PA11)��Sidetone�M�����o�͂����(500Hz ��`�g)�̂ň��d�X�s�[�J�[���Ȃ��Ń��j�^�ł���BPA11�ƈ��d�X�s�[�J�Ƃ̊Ԃɂ͒���ɒ�R(1k���Ȃ�)������B
- Keyer�̃X�s�[�h�ƃu���[�N�C�����Ԃɂ��ă��j���[�͖������B�ύX�������ꍇ�́A �\�[�X�R�[�h�� define �̒l���C������K�v������B
- keyer�t�H���_�́ASSB_trx�t�H���_�ɓ����

### Step5:
- iambic�L�[���[��Sidetone���g����600Hz�ɕύX(��M���̃g�[�����g���ƈ�v������)
- Sidetone���I�[�f�B�I�R�[�f�b�NIC�o�R�̃w�b�h�t�H���o�͂ɕύX
- PA11�̏o�͂�RC��LPF��ʂ��ăI�[�f�B�I�R�[�f�b�N��IN1L/R�ɓ��͂���B
[_RC LPF Schematic_](hardware/SDR-3_SideTone.pdf)
[_Photo_](hardware/SDR-3_sidetone.JPG)
- Sidetone�̉��ʂɂ��ă��j���[�͖������B�ύX�������ꍇ�́A tlv320aic3204.c �̏C�����e��ύX����K�v������B
- Step5�t�H���_���ɂ���keyer�t�H���_���g�� (keyer�t�H���_�������ւ���K�v����B���e�X�V����)

### Step6:
- setting���j���[�ɁA���L��iambic�L�[���[�̐ݒ荀�ڂ�ǉ�
- Speed�F10�`40 WPM
- Break-in ���ԁF 50�`500 ms (���ۂ́A���\ms�̌덷����)
- Sidetone ���ʁF 0 �` 117
- Step6�t�H���_���ɂ���keyer�t�H���_���g�� (keyer�t�H���_�������ւ���K�v����B���e�X�V����)
- radio.c �ɂ����� CW���[�h�ǉ����̃o�O�C��

### Step7:
- �L�[���[�Ƀo�O�L�[/�X�g���[�g�L�[�̋@�\��ǉ�
- setting���j���[�� iambic �Ƃ��Ďg�p���邩 �o�O�L�[/�X�g���[�g�L�Ƃ��Ďg�p���邩��I���ł���
- �X�g���[�g�L�[���g�p����ꍇ�́A�X�g���[�g�L�[�� Dash key (PA6) ���ɐڑ�����
- Step7�t�H���_���ɂ���keyer�t�H���_���g�� (keyer�t�H���_�������ւ���K�v����B���e�X�V����)

