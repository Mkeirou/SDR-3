# SDR-3 transceiver improvement

## CW機能追加
### はじめに
- ソフトウェア開発環境の構築方法はおじさん工房のHPに掲載されています。
- 使用している SDR-3 ソースコードはトランジスタ技術 2018年 9月号 付録DVD-ROMに納められています。
- 追加作業は 各Step毎に「変更→動作確認」を行なってください。1つ前のStepのファイルを保存しておくと上手く動作しない時に変更前後のファイルの比較ができたり、手戻りが容易になります。
- 各Stepのフォルダに jpeg と txt が組で格納されています。jpeg は変更前後のファイル内容の比較結果で変更箇所を示しています。txtファイルを活用してファイルを修正します。
- トラブル回避のため、make clean を行ってから make してください。iambic.o は個別に削除するか、makefileを修正して対処してください。
- Flash Loader Demonstrator を使用して STM32に書き込みを行う際には「Global Erase」のラジオボタンを選択して下さい。

### Step1:
- おじさん工房のHPに掲載されているパッチの適用

### Step2:
- CWモード(CW Lower と CW Upper)を追加
- CW受信音が600Hzになるようにチューニングすると、LCD上に表示されている周波数が送信周波数となる。
- PTTを押すと送信となる。
- CW波のON/OFF時に窓関数は使用していない(CW波は急峻に立ち上がり/立下りする)。

### Step3:
- CWキーイング機能を追加
- CW key に PA5 を 使用。R2 に 3.3kΩを実装する。PA5は10pinのピンヘッダの脇に端子が配置されている。
- PTT で送信状態にして、PA5をGNDに落とすとCW波の送信となる。
- CW波のON/OFFは窓関数(raised cosine)を使用(CW波は緩やかに立ち上がり/立下りする)。

### Step4:
- iambicキーヤー機能を追加
- Dot key に PA5 を、 Dash key に PA6 を使用。 R3 に 3.3kΩを実装する。PA6も10pinのピンヘッダの脇に端子が配置されている。
- PA5/PA6をGNDに落とすとDot/DashのCW波が送信される (PTTの操作は不要)。
- USB端子(PA11)にSidetone信号が出力される(500Hz 矩形波)ので圧電スピーカーをつないでモニタできる。PA11と圧電スピーカとの間には直列に抵抗(1kΩなど)を入れる。
- Keyerのスピードとブレークイン時間についてメニューは未実装。変更したい場合は、 ソースコードの define の値を修正する必要がある。
- keyerフォルダをSSB_trxフォルダに入れる

### Step5:
- iambicキーヤーのSidetone周波数を600Hzに変更(受信時のトーン周波数と一致させた)
- SidetoneをオーディオコーデックIC経由のヘッドフォン出力に変更
- PA11の出力をRCのLPFを通してオーディオコーデックのIN1L/Rに入力する。
[_RC LPF Schematic_](hardware/SDR-3_SideTone.pdf)
[_Photo_](hardware/SDR-3_sidetone.JPG)
- Sidetoneの音量調整についてメニューは未実装。変更したい場合は、 tlv320aic3204.c の修正内容を変更する必要がある。
- Step5フォルダ中にあるkeyerフォルダを使う (keyerフォルダを差し替える必要あり。内容更新あり)

### Step6:
- settingメニューに、下記のiambicキーヤーの設定項目を追加
- Speed：10〜40 WPM
- Break-in 時間： 50〜500 ms (実際は、数十msの誤差あり)
- Sidetone 音量： 0 〜 117
- Step6フォルダ中にあるkeyerフォルダを使う (keyerフォルダを差し替える必要あり。内容更新あり)
- radio.c における CWモード追加時のバグ修正

### Step7:
- キーヤーにバグキー/ストレートキーの機能を追加
- settingメニューで iambic として使用するか バグキー/ストレートキとして使用するかを選択できる
- ストレートキーを使用する場合は、ストレートキーを Dash key (PA6) 側に接続する
- Step7フォルダ中にあるkeyerフォルダを使う (keyerフォルダを差し替える必要あり。内容更新あり)

### Step8:
- Transceiver 画面でキーヤーのスピードを設定できるように変更
- CW送信中は、ロータリーエンコーダ #2 の回転によりスピードが変更できる
- 受信中は、ロータリーエンコーダ #2のプッシュスイッチを(2回)押して "Keyer SPD" を選んだ後、ロータリーエンコーダ #2の回転によりスピードが変更できる
- Step8では、keyerフォルダ内容の変更はなし

### Step9:
- オフバンド時やsettingメニュー表示中にキーヤーを操作した時にSidetoneが漏れ聞こえる症状の対策
- Step9フォルダ中にあるkeyerフォルダを使う (keyerフォルダを差し替える必要あり。内容更新あり)

### Step10:
- settingメニューに CWピッチ周波数の設定項目を追加
- スペクトラム表示中に CWモード時のチューニングポイントを示す縦の赤ラインを追加
- CWピッチ周波数の設定範囲は 500Hz 〜 800Hz。 10Hz単位で変更可能
- CW受信音が好みのトーンとなるように設定するとSidetoneのトーン周波数も連動して変更される。同様にスペクトラム表示中のチューニングポイントを示す赤ラインの位置も連動して変更される。
- Step10では、keyerフォルダ内容の変更はなし

### Step11:
- CW用受信フィルタの追加
- LPF: CWモード時、600Hz, 700Hz, 800Hz, 900Hz, 1kHz の 5種類を選択した時は 8次IIRフィルタを使用する。CWモード以外の時またはCWモード時でもカットオフ周波数が2.2kHzより上のLPFを選択した場合は デフォルトの6次IIRフィルタを使用する。
- HPF: CWモード時、8次IIRフィルタを使用。CWモード以外の時は デフォルトの2次IIRフィルタを使用する。
- CWモード時、フィルタ通過帯域がわかるようにスペクトラム表示のハイライト領域が HPFの選択で変化するようにした。
- 各フィルタ係数値はお試しレベル。
- Step11では、keyerフォルダ内容の変更はなし

### Step12:
- CW送信波の帯域幅の広がりを改善
- CW送信波の立ち上がり/立ち下り時間を従来の 5.3ms(fs=12kHz 64サンプル分)から、8ms (96サンプル分)に変更。
- Step12では、keyerフォルダ内容の変更はなし
