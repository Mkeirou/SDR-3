# SDR-3 transceiver improvement

## CW�@�\�ǉ�
### �͂��߂�
- �\�t�g�E�F�A�J�����̍\�z���@�͂�������H�[��HP�Ɍf�ڂ���Ă��܂��B
- �g�p���Ă��� SDR-3 �\�[�X�R�[�h�̓g�����W�X�^�Z�p 2018�N 9���� �t�^DVD-ROM�ɔ[�߂��Ă��܂��B
- �ǉ���Ƃ� �eStep���Ɂu�ύX������m�F�v���s�Ȃ��Ă��������B1�O��Step�̃t�@�C����ۑ����Ă����Ə�肭���삵�Ȃ����ɕύX�O��̃t�@�C���̔�r���ł�����A��߂肪�e�ՂɂȂ�܂��B
- �eStep�̃t�H���_�� jpeg �� txt ���g�Ŋi�[����Ă��܂��Bjpeg �͕ύX�O��̃t�@�C�����e�̔�r���ʂŕύX�ӏ��������Ă��܂��Btxt�t�@�C�������p���ăt�@�C�����C�����܂��B
- �g���u������̂��߁Amake clean ���s���Ă��� make ���Ă��������Biambic.o �͌ʂɍ폜���邩�Amakefile���C�����đΏ����Ă��������B
- Flash Loader Demonstrator ���g�p���� STM32�ɏ������݂��s���ۂɂ́uGlobal Erase�v�̃��W�I�{�^����I�����ĉ������B

### Step1:
- ��������H�[��HP�Ɍf�ڂ���Ă���p�b�`�̓K�p

### Step2:
- CW���[�h(CW Lower �� CW Upper)��ǉ�
- CW��M����600Hz�ɂȂ�悤�Ƀ`���[�j���O����ƁALCD��ɕ\������Ă�����g�������M���g���ƂȂ�B
- PTT�������Ƒ��M�ƂȂ�B
- CW�g��ON/OFF���ɑ��֐��͎g�p���Ă��Ȃ�(CW�g�͋}�s�ɗ����オ��/�����肷��)�B

### Step3:
- CW�L�[�C���O�@�\��ǉ�
- CW key �� PA5 �� �g�p�BR2 �� 3.3k������������BPA5��10pin�̃s���w�b�_�̘e�ɒ[�q���z�u����Ă���B
- PTT �ő��M��Ԃɂ��āAPA5��GND�ɗ��Ƃ���CW�g�̑��M�ƂȂ�B
- CW�g��ON/OFF�͑��֐�(raised cosine)���g�p(CW�g�͊ɂ₩�ɗ����オ��/�����肷��)�B

### Step4:
- iambic�L�[���[�@�\��ǉ�
- Dot key �� PA5 ���A Dash key �� PA6 ���g�p�B R3 �� 3.3k������������BPA6��10pin�̃s���w�b�_�̘e�ɒ[�q���z�u����Ă���B
- PA5/PA6��GND�ɗ��Ƃ���Dot/Dash��CW�g�����M����� (PTT�̑���͕s�v)�B
- USB�[�q(PA11)��Sidetone�M�����o�͂����(500Hz ��`�g)�̂ň��d�X�s�[�J�[���Ȃ��Ń��j�^�ł���BPA11�ƈ��d�X�s�[�J�Ƃ̊Ԃɂ͒���ɒ�R(1k���Ȃ�)������B
- Keyer�̃X�s�[�h�ƃu���[�N�C�����Ԃɂ��ă��j���[�͖������B�ύX�������ꍇ�́A �\�[�X�R�[�h�� define �̒l���C������K�v������B
- keyer�t�H���_��SSB_trx�t�H���_�ɓ����

### Step5:
- iambic�L�[���[��Sidetone���g����600Hz�ɕύX(��M���̃g�[�����g���ƈ�v������)
- Sidetone���I�[�f�B�I�R�[�f�b�NIC�o�R�̃w�b�h�t�H���o�͂ɕύX
- PA11�̏o�͂�RC��LPF��ʂ��ăI�[�f�B�I�R�[�f�b�N��IN1L/R�ɓ��͂���B
[_RC LPF Schematic_](hardware/SDR-3_SideTone.pdf)
[_Photo_](hardware/SDR-3_sidetone.JPG)
- Sidetone�̉��ʒ����ɂ��ă��j���[�͖������B�ύX�������ꍇ�́A tlv320aic3204.c �̏C�����e��ύX����K�v������B
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

### Step8:
- Transceiver ��ʂŃL�[���[�̃X�s�[�h��ݒ�ł���悤�ɕύX
- CW���M���́A���[�^���[�G���R�[�_ #2 �̉�]�ɂ��X�s�[�h���ύX�ł���
- ��M���́A���[�^���[�G���R�[�_ #2�̃v�b�V���X�C�b�`��(2��)������ "Keyer SPD" ��I�񂾌�A���[�^���[�G���R�[�_ #2�̉�]�ɂ��X�s�[�h���ύX�ł���
- Step8�ł́Akeyer�t�H���_���e�̕ύX�͂Ȃ�

### Step9:
- �I�t�o���h����setting���j���[�\�����ɃL�[���[�𑀍삵������Sidetone���R�ꕷ������Ǐ�̑΍�
- Step9�t�H���_���ɂ���keyer�t�H���_���g�� (keyer�t�H���_�������ւ���K�v����B���e�X�V����)

### Step10:
- setting���j���[�� CW�s�b�`���g���̐ݒ荀�ڂ�ǉ�
- �X�y�N�g�����\������ CW���[�h���̃`���[�j���O�|�C���g�������c�̐ԃ��C����ǉ�
- CW�s�b�`���g���̐ݒ�͈͂� 500Hz �` 800Hz�B 10Hz�P�ʂŕύX�\
- CW��M�����D�݂̃g�[���ƂȂ�悤�ɐݒ肷���Sidetone�̃g�[�����g�����A�����ĕύX�����B���l�ɃX�y�N�g�����\�����̃`���[�j���O�|�C���g�������ԃ��C���̈ʒu���A�����ĕύX�����B
- Step10�ł́Akeyer�t�H���_���e�̕ύX�͂Ȃ�

### Step11:
- CW�p��M�t�B���^�̒ǉ�
- LPF: CW���[�h���A600Hz, 700Hz, 800Hz, 900Hz, 1kHz �� 5��ނ�I���������� 8��IIR�t�B���^���g�p����BCW���[�h�ȊO�̎��܂���CW���[�h���ł��J�b�g�I�t���g����2.2kHz�����LPF��I�������ꍇ�� �f�t�H���g��6��IIR�t�B���^���g�p����B
- HPF: CW���[�h���A8��IIR�t�B���^���g�p�BCW���[�h�ȊO�̎��� �f�t�H���g��2��IIR�t�B���^���g�p����B
- CW���[�h���A�t�B���^�ʉߑш悪�킩��悤�ɃX�y�N�g�����\���̃n�C���C�g�̈悪 HPF�̑I���ŕω�����悤�ɂ����B
- �e�t�B���^�W���l�͂��������x���B
- Step11�ł́Akeyer�t�H���_���e�̕ύX�͂Ȃ�

### Step12:
- CW���M�g�̑ш敝�̍L��������P
- CW���M�g�̗����オ��/�������莞�Ԃ��]���� 5.3ms(fs=12kHz 64�T���v����)����A8ms (96�T���v����)�ɕύX�B
- Step12�ł́Akeyer�t�H���_���e�̕ύX�͂Ȃ�

### Step13:
- �g�����V�[�o�[��ʂ̕ύX�B���e�͉��L�B
- �A�i���O�^�C�v��S���[�^�[�\����ǉ�
- F.Step�\���̒ǉ�
- ��L�ɔ����A���̃��j���[���ڂ̕\���̏��T�C�Y��
- Step13�ł́Akeyer�t�H���_���e�̕ύX�͂Ȃ�

### Step14:
- S���[�^�[�̕����Ղ̕`����@��ύX
- ��96�h�b�g�~�c47�h�b�g�̃r�b�g�}�b�v�f�[�^���g�p����S���[�^�[�̕����Ղ�`��
- �����Ղ̃r�b�g�}�b�v�f�[�^�쐬�c�[���Ƃ���Excel�V�[�g���g�p (firmware/S-meter Panel Data Generator/s-meter-panel_data_generator.xls)
- Step14�ł́Akeyer�t�H���_���e�̕ύX�͂Ȃ�

### Step15:
- S���[�^�[�̎�ނƂ��� ��ǂ��񂪃f�U�C�����ꂽS���[�^�[���^�C�v1�Ƃ��Ēǉ��B�I���W�i���̓^�C�v0�B
- S���[�^�[�̎w�j�̐F��8�F(���A�A�ԁA�΁A�V�A���A�}�[���^�A���A��)�̒�����I���ł���B
- �^�C�v1�̏ꍇ�́AS���[�^�[�̎w�j�̑�����I���ł���(��������͓̂J������������̃A�C�f�A)
- setting ���j���[�ł�����S���[�^�[�^�C�v�A�w�j�̐F�A������ݒ�ł���B
- �^�C�v1�ɃR�[���T�C���∤�̂Ȃǂ�\���������ꍇ�́AExcel�V�[�g(s-meter-panel_data_generator_r1(��ǂ����).xls)���g�p����B�t���[�n���h�ŕ�����`���Ă��ǂ����Afont8.c���Q�l�ɂ���Ƒ������ƕ����f�U�C��������ł���B
- Step15�ł́Akeyer�t�H���_���e�̕ύX�͂Ȃ�

### Step16:
- S���[�^�[�̎�ނƂ��� �X��2�^�C�v���ǉ��B���v4�^�C�v�B
- �^�C�v2�́A�܂��̂���f�U�C���BExcel�V�[�g�́As-meter-panel_data_generator_r1(�܂��̂����).xls (BBS�̏������ݏ������ɂ�ǂ�����Excel�t�@�C�������ύX���č쐬)
- �^�C�v3�́A����ӂ񂳂�f�U�C���BExcel�V�[�g�́As-meter-panel_data_generator_r2(����ӂ񂳂��).xls
- �^�C�v3�̏ꍇ�́Asetting���j���[�� Needle bold ���w�肷��ƒʏ�̃o�[�\���ɂł���B
- Excel�V�[�g��C����p�z��f�[�^�̐������Ɍ�肪�������Bgit��upload���Ă���S�Ă�Excel�V�[�g���C��
- Step16�ł́Akeyer�t�H���_���e�̕ύX�͂Ȃ�

## ���̑�
### Appendix1:
- �t�^DVD-ROM�̃\�[�X�ɑ΂��āAmain20180812.hex �� setting���j���[�� "Freq Popup"�� "OFF" �ɂ����̂Ɠ�������ɂ��邽�߂̏C���ӏ��B
- radio.c �� radio_rotaryenc ���� 4�ӏ����R�����g�A�E�g����B
```c
   case 0:
     if( (rot>=ACCEL_TH) || (rot<=-ACCEL_TH) ) rot *= ACCEL;
     freq_setting( freq + rot*freqstep );
//   if( popuptime_default ) {
//     gui_popup_show( str_freq );
//   }else{
       gui_update();
//   }
     break;
```

### Appendix2:
- �`���[�j���O����̑�����ݒ�̕ύX
- ���[�^���[�G���R�[�_�̑��񂵔��肵�����l�Ǝ��g�������ʂ̕ύX�ӏ�
- main.h �� ACCEL��ACCEL_TH��ύX����B���L���10�{��
```c
#define ACCEL             (10)          // ���[�^���[�G���R�[�_�[�����W��
#define ACCEL_TH          (2)           // ���[�^���[�G���R�[�_�[�����X���b�V�����h
```
