#include "NexButton.h"
#include "NexText.h"
#include "Arduino.h"
#include "NexDualStateButton.h"
#include "NexPage.h"
#include "NexNumber.h"
#include "NexProgressbar.h"
#include "Wire.h"
#include <Nextion.h>

NexWaveform s0 = NexWaveform(0, 21, "s0");
NexWaveform s1 = NexWaveform(0, 22, "s1");
NexWaveform s120 = NexWaveform(12, 20, "s120");
NexNumber n00 = NexNumber(0, 2, "n00");
NexNumber n1 = NexNumber(0, 23, "n1");
NexNumber n01 = NexNumber(0, 3, "n01");
NexNumber n02 = NexNumber(0, 6, "n02");
NexNumber n03 = NexNumber(0, 7, "n03");
NexNumber n04 = NexNumber(0, 4, "n04");
NexNumber n05 = NexNumber(0, 8, "n05");
NexNumber n40 = NexNumber(4, 1, "n40");
NexNumber n41 = NexNumber(4, 2, "n41");
NexNumber n42 = NexNumber(4, 7, "n42");
NexNumber n43 = NexNumber(4, 8, "n43");
NexNumber n44 = NexNumber(4, 9, "n44");
NexDSButton bt10 = NexDSButton(0, 5, "bt10");
NexDSButton bt11 = NexDSButton(0, 9, "bt11");
NexDSButton bt12 = NexDSButton(0, 10, "bt12");
NexDSButton bt13 = NexDSButton(0, 11, "bt13");
NexDSButton bt14 = NexDSButton(0, 13, "bt14");
NexDSButton bt15 = NexDSButton(0, 12, "bt15");
NexDSButton bt16 = NexDSButton(0, 14, "bt16");
NexDSButton bt17 = NexDSButton(0, 15, "bt17");
NexDSButton bt18 = NexDSButton(0, 16, "bt18");
NexDSButton bt19 = NexDSButton(0, 17, "bt19");
NexDSButton bt20 = NexDSButton(0, 18, "bt20");
NexDSButton bt09 = NexDSButton(0, 24, "bt09");
NexDSButton bt21 = NexDSButton(0, 19, "bt21");
NexProgressBar j10  = NexProgressBar(1, 1, "j10");
NexButton b00 = NexButton(0, 1, "b00");
NexButton b20 = NexButton(2, 2, "b20");
NexButton b21 = NexButton(2, 3, "b21");
NexButton b22 = NexButton(2, 4, "b22");
NexButton b23 = NexButton(2, 5, "b23");
NexButton b24 = NexButton(2, 6, "b24");
NexButton b25 = NexButton(2, 8, "b25");
NexButton b26 = NexButton(2, 10, "b26");
NexButton b27 = NexButton(2, 11, "b27");
NexButton b28 = NexButton(2, 1, "b28");
NexButton b29 = NexButton(2, 7, "b29");
NexButton b210 = NexButton(2, 9, "b210");
NexButton b211 = NexButton(2, 12, "b211");
NexButton m30 = NexButton(3, 2, "m30");
NexButton b30 = NexButton(3, 2, "b30");
NexDSButton bt30 = NexDSButton(3, 3, "bt30");
NexButton m40 = NexButton(4, 3, "m40");
NexButton m41 = NexButton(4, 4, "m41");
NexButton m42 = NexButton(4, 5, "m42");
NexButton m43 = NexButton(4, 6, "m43");
NexButton m44 = NexButton(4, 10, "m44");
NexButton m45 = NexButton(4, 11, "m45");
NexButton m46 = NexButton(4, 12, "m46");
NexButton m47 = NexButton(4, 13, "m47");
NexButton m48 = NexButton(4, 14, "m48");
NexButton m49 = NexButton(4, 15, "m49");
NexButton m410 = NexButton(4, 16, "m410");
NexButton m411 = NexButton(4, 17, "m411");
NexDSButton bt50 = NexDSButton(5, 1, "bt50");
NexDSButton bt51 = NexDSButton(5, 2, "bt51");
NexButton m50 = NexButton(5, 3, "m50");
NexButton m51 = NexButton(5, 8, "m51");
NexButton m52 = NexButton(5, 9, "m52");
NexButton m53 = NexButton(5, 10, "m53");
NexButton m54 = NexButton(5, 11, "m54");
NexButton m55 = NexButton(5, 12, "m55");
NexButton m56 = NexButton(5, 14, "m56");
NexButton m57 = NexButton(5, 13, "m57");
NexButton m58 = NexButton(5, 15, "m58");
NexNumber n50 = NexNumber(5, 4, "n50");
NexNumber n51 = NexNumber(5, 5, "n51");
NexNumber n52 = NexNumber(5, 6, "n52");
NexNumber n53 = NexNumber(5, 7, "n53");
NexDSButton bt60 = NexDSButton(6, 1, "bt60");
NexDSButton bt61 = NexDSButton(6, 2, "bt61");
NexButton m60 = NexButton(6, 3, "m60");
NexButton m61 = NexButton(6, 8, "m61");
NexButton m62 = NexButton(6, 9, "m62");
NexButton m63 = NexButton(6, 10, "m63");
NexButton m64 = NexButton(6, 11, "m64");
NexButton m65 = NexButton(6, 12, "m65");
NexButton m66 = NexButton(6, 14, "m66");
NexButton m67 = NexButton(6, 13, "m67");
NexButton m68 = NexButton(6, 15, "m68");
NexNumber n60 = NexNumber(6, 4, "n60");
NexNumber n61 = NexNumber(6, 5, "n61");
NexNumber n62 = NexNumber(6, 6, "n62");
NexNumber n63 = NexNumber(6, 7, "n63");
NexDSButton bt70 = NexDSButton(7, 1, "bt70");
NexDSButton bt71 = NexDSButton(7, 2, "bt71");
NexButton m70 = NexButton(7, 3, "m70");
NexButton m71 = NexButton(7, 8, "m71");
NexButton m72 = NexButton(7, 9, "m72");
NexButton m73 = NexButton(7, 10, "m73");
NexButton m74 = NexButton(7, 11, "m74");
NexButton m75 = NexButton(7, 12, "m75");
NexButton m76 = NexButton(7, 14, "m76");
NexButton m77 = NexButton(7, 13, "m77");
NexButton m78 = NexButton(7, 15, "m78");
NexNumber n70 = NexNumber(7, 4, "n70");
NexNumber n71 = NexNumber(7, 5, "n71");
NexNumber n72 = NexNumber(7, 6, "n72");
NexNumber n73 = NexNumber(7, 7, "n73");
NexDSButton bt80 = NexDSButton(8, 1, "bt80");
NexDSButton bt81 = NexDSButton(8, 2, "bt81");
NexButton m80 = NexButton(8, 3, "m80");
NexButton m81 = NexButton(8, 8, "m81");
NexButton m82 = NexButton(8, 9, "m82");
NexButton m83 = NexButton(8, 10, "m83");
NexButton m84 = NexButton(8, 11, "m84");
NexButton m85 = NexButton(8, 12, "m85");
NexButton m86 = NexButton(8, 14, "m86");
NexButton m87 = NexButton(8, 13, "m87");
NexButton m88 = NexButton(8, 15, "m88");
NexNumber n80 = NexNumber(8, 4, "n80");
NexNumber n81 = NexNumber(8, 5, "n81");
NexNumber n82 = NexNumber(8, 6, "n82");
NexNumber n83 = NexNumber(8, 7, "n83");
NexDSButton bt90 = NexDSButton(9, 1, "bt90");
NexDSButton bt91 = NexDSButton(9, 2, "bt91");
NexButton m90 = NexButton(9, 3, "m90");
NexButton m91 = NexButton(9, 6, "m91");
NexButton m92 = NexButton(9, 7, "m92");
NexNumber n90 = NexNumber(9, 4, "n90");
NexNumber n91 = NexNumber(9, 5, "n91");
NexDSButton bt100 = NexDSButton(10, 1, "bt100");
NexButton m100 = NexButton(10, 2, "m100");
NexButton m110 = NexButton(11, 2, "m110");
NexDSButton bt122 = NexDSButton(12, 1, "bt122");
NexDSButton bt123 = NexDSButton(12, 8, "bt123");
NexButton m120 = NexButton(12, 2, "m120");
NexButton m121 = NexButton(12, 21, "m121");
NexButton m123 = NexButton(12, 6, "m123");
NexButton m124 = NexButton(12, 7, "m124");
NexButton m125 = NexButton(12, 4, "m125");
NexButton m126 = NexButton(12, 5, "m126");
NexNumber n120 = NexNumber(12, 3, "n120");
NexNumber n121 = NexNumber(12, 9, "n121");
NexNumber n122 = NexNumber(12, 10, "n122");
NexNumber n123 = NexNumber(12, 11, "n123");
NexNumber n124 = NexNumber(12, 12, "n124");
NexNumber n125 = NexNumber(12, 13, "n125");
NexNumber n126 = NexNumber(12, 14, "n126");
NexNumber n127 = NexNumber(12, 15, "n127");
NexNumber n128 = NexNumber(12, 16, "n128");
NexNumber n129 = NexNumber(12, 17, "n129");
NexNumber n1210 = NexNumber(12, 18, "n1210");
NexNumber n1211 = NexNumber(12, 19, "n1211");
NexButton b138 = NexButton(13, 27, "b138");
NexDSButton bt131 = NexDSButton(13, 1, "bt131");
NexDSButton bt132 = NexDSButton(13, 2, "bt132");
NexDSButton bt133 = NexDSButton(13, 3, "bt133");
NexDSButton bt134 = NexDSButton(13, 4, "bt134");
NexDSButton bt135 = NexDSButton(13, 11, "bt135");
NexDSButton bt136 = NexDSButton(13, 12, "bt136");
NexNumber n130 = NexNumber(13, 15, "n130");
NexNumber n133 = NexNumber(13, 17, "n133");
NexNumber n135 = NexNumber(13, 19, "n135");
NexNumber n137 = NexNumber(13, 21, "n137");
NexNumber n139 = NexNumber(13, 23, "n139");
NexNumber n1311 = NexNumber(13, 25, "n1311");
NexNumber n132 = NexNumber(13, 15, "n132");
NexNumber n134 = NexNumber(13, 17, "n134");
NexNumber n136 = NexNumber(13, 19, "n136");
NexNumber n138 = NexNumber(13, 21, "n138");
NexNumber n1310 = NexNumber(13, 23, "n1310");
NexNumber n1312 = NexNumber(13, 26, "n1312");
NexButton m131 = NexButton(13, 7, "m131");
NexButton m132 = NexButton(13, 8, "m132");
NexButton m133 = NexButton(13, 9, "m133");
NexButton m134 = NexButton(13, 10, "m134");
NexButton m135 = NexButton(13, 13, "m135");
NexButton m136 = NexButton(13, 14, "m136");
NexButton m137 = NexButton(13, 5, "m137");
NexButton m138 = NexButton(13, 6, "m138");
NexButton b140 = NexButton(14, 2, "b140");
NexButton b148 = NexButton(14, 1, "b148");
NexPage page0 = NexPage(0, 0, "page0");
NexPage page1 = NexPage(1, 0, "page1");
NexPage page2 = NexPage(2, 0, "page2");
NexPage page3 = NexPage(3, 0, "page3");
NexPage page4 = NexPage(4, 0, "page4");
NexPage page5 = NexPage(5, 0, "page5");
NexPage page6 = NexPage(6, 0, "page6");
NexPage page7 = NexPage(7, 0, "page7");
NexPage page8 = NexPage(8, 0, "page8");
NexPage page9 = NexPage(9, 0, "page9");
NexPage page10 = NexPage(10, 0, "page10");
NexPage page11 = NexPage(11, 0, "page11");
NexPage page12 = NexPage(12, 0, "page12");
NexPage page13 = NexPage(13, 0, "page13");
NexPage page14 = NexPage(14, 0, "page14");

NexTouch *nex_Listen_List[] =
{
  &page0, &bt10,
  &b00,  &page1,
  &b20, &b21, &b22, &b23,
  &b24, &b25, &b26, &b27,  &bt21, &b29, &b211,
  &b28, &page2, &m30, &b30, &bt30,
  &page4, &m40, &m41, &m42, &m43, &m44, &m45, &m46, &m47, &m48, &m49, &m410, &m411,
  &page5, &m50, &bt50, &bt51, &m51, &m52, &m53, &m54, &m55, &m56, &m57, &m58,
  &page6, &m60, &bt60, &bt61, &m61, &m62, &m63, &m64, &m65, &m66, &m67, &m68,
  &bt10, &bt11, &bt12, &bt13, &bt14, &bt15, &bt16, &bt17, &bt18, &bt19, &bt20,
  &page7, &m70, &bt70, &bt71, &m71, &m72, &m73, &m74, &m75, &m76, &m77, &m78,
  &page8, &m80, &bt80, &bt81, &m81, &m82, &m83, &m84, &m85, &m86, &m87, &m88,
  &page9, &bt90, &bt91, &m90, &m91, &m92,
  &page10, &bt100, &m100,
  &page11, &m110,
  &page12, &m120, &m121, &bt122, &bt123, &m123, &m124, &m125, &m126, &n120, &n121, &n122, &n123, &n124, &n125, &n126, &n127,  &n128, &n129, &n1210,  &n1211,
  &page13, &b138, &bt131, &bt132, &bt133, &bt134, &bt135, &bt136, &n130, &n133, &n135, &n137, &n139, &n1311, &n132, &n134, &n136, &n138, &n1310, &n1312, &m131, &m132, &m133, &m134, &m135, &m136, &m137, &m138,
  &page14, &b140, &b148,


  NULL
};
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
 nexInit();

  b00.attachPop(b00PopCallback, &b00);
  b20.attachPop(b20PopCallback, &b20);
  b21.attachPop(b21PopCallback, &b21);
  b22.attachPop(b22PopCallback, &b22);
  b23.attachPop(b23PopCallback, &b23);
  b24.attachPop(b24PopCallback, &b24);
  b25.attachPop(b25PopCallback, &b25);
  b26.attachPop(b26PopCallback, &b26);
  b27.attachPop(b27PopCallback, &b27);
  b28.attachPop(b28PopCallback, &b28);
  b211.attachPop(b211PopCallback, &b211);
  b29.attachPop(b29PopCallback, &b29);
  m30.attachPop(m30PopCallback, &m30);
  b30.attachPop(b30PopCallback, &b30);
  bt30.attachPop(bt30PopCallback, &bt30);

  m40.attachPop(m40PopCallback, &m40);
  m41.attachPop(m41PopCallback, &m41);
  m42.attachPop(m42PopCallback, &m42);
  m43.attachPop(m43PopCallback, &m43);
  m44.attachPop(m44PopCallback, &m44);
  m45.attachPop(m45PopCallback, &m45);
  m46.attachPop(m46PopCallback, &m46);
  m47.attachPop(m47PopCallback, &m47);
  m48.attachPop(m48PopCallback, &m48);
  m49.attachPop(m49PopCallback, &m49);
  m410.attachPop(m410PopCallback, &m410);
  m411.attachPop(m411PopCallback, &m411);
  bt50.attachPop(bt50PopCallback, &bt50);
  bt51.attachPop(bt51PopCallback, &bt51);
  m50.attachPop(m50PopCallback, &m50);
  m51.attachPop(m51PopCallback, &m51);
  m52.attachPop(m52PopCallback, &m52);
  m53.attachPop(m53PopCallback, &m53);
  m54.attachPop(m54PopCallback, &m54);
  m55.attachPop(m55PopCallback, &m55);
  m56.attachPop(m56PopCallback, &m56);
  m57.attachPop(m57PopCallback, &m57);
  m58.attachPop(m58PopCallback, &m58);


  bt60.attachPop(bt60PopCallback, &bt60);
  bt61.attachPop(bt61PopCallback, &bt61);
  m60.attachPop(m60PopCallback, &m60);
  m61.attachPop(m61PopCallback, &m61);
  m62.attachPop(m62PopCallback, &m62);
  m63.attachPop(m63PopCallback, &m63);
  m64.attachPop(m64PopCallback, &m64);
  m65.attachPop(m65PopCallback, &m65);
  m66.attachPop(m66PopCallback, &m66);
  m67.attachPop(m67PopCallback, &m67);
  m68.attachPop(m68PopCallback, &m68);

  bt70.attachPop(bt70PopCallback, &bt70);
  bt71.attachPop(bt71PopCallback, &bt71);
  m70.attachPop(m70PopCallback, &m70);
  m71.attachPop(m71PopCallback, &m71);
  m72.attachPop(m72PopCallback, &m72);
  m73.attachPop(m73PopCallback, &m73);
  m74.attachPop(m74PopCallback, &m74);
  m75.attachPop(m75PopCallback, &m75);
  m76.attachPop(m76PopCallback, &m76);
  m77.attachPop(m77PopCallback, &m77);
  m78.attachPop(m78PopCallback, &m78);

  bt80.attachPop(bt80PopCallback, &bt80);
  bt81.attachPop(bt81PopCallback, &bt81);
  m80.attachPop(m80PopCallback, &m80);
  m81.attachPop(m81PopCallback, &m81);
  m82.attachPop(m82PopCallback, &m82);
  m83.attachPop(m83PopCallback, &m83);
  m84.attachPop(m84PopCallback, &m84);
  m85.attachPop(m85PopCallback, &m85);
  m86.attachPop(m86PopCallback, &m86);
  m87.attachPop(m87PopCallback, &m87);
  m88.attachPop(m88PopCallback, &m88);

  bt90.attachPop(bt90PopCallback, &bt90);
  bt91.attachPop(bt91PopCallback, &bt91);
  m90.attachPop(m90PopCallback, &m90);
  m91.attachPop(m91PopCallback, &m91);
  m92.attachPop(m92PopCallback, &m92);

  bt100.attachPop(bt100PopCallback, &bt100);
  m100.attachPop(m100PopCallback, &m100);
  m110.attachPop(m110PopCallback, &m110);
  bt10.attachPop(bt10PopCallback, &bt10);
  bt11.attachPop(bt11PopCallback, &bt11);
  bt12.attachPop(bt12PopCallback, &bt12);
  bt13.attachPop(bt13PopCallback, &bt13);
  bt15.attachPop(bt15PopCallback, &bt15);
  bt16.attachPop(bt16PopCallback, &bt16);
  bt17.attachPop(bt17PopCallback, &bt17);
  bt18.attachPop(bt18PopCallback, &bt18);
  bt19.attachPop(bt19PopCallback, &bt19);
  //bt20.attachPop(bt20PopCallback, &bt20);
  bt21.attachPop(bt21PopCallback, &bt21);


  bt122.attachPop(bt122PopCallback, &bt122);
  bt123.attachPop(bt123PopCallback, &bt123);
  m120.attachPop(m120PopCallback, &m120);
  m123.attachPop(m123PopCallback, &m123);
  m124.attachPop(m124PopCallback, &m124);
  m125.attachPop(m125PopCallback, &m125);
  m126.attachPop(m126PopCallback, &m126);
  n120.attachPop(n120PopCallback, &n120);
  n121.attachPop(n121PopCallback, &n121);
  n122.attachPop(n122PopCallback, &n122);
  n123.attachPop(n123PopCallback, &n123);
  n124.attachPop(n124PopCallback, &n124);
  n125.attachPop(n125PopCallback, &n125);
  n126.attachPop(n126PopCallback, &n126);
  n127.attachPop(n127PopCallback, &n127);
  n128.attachPop(n128PopCallback, &n128);
  n129.attachPop(n129PopCallback, &n129);
  n1210.attachPop(n1210PopCallback, &n1210);
  n1211.attachPop(n1211PopCallback, &n1211);
  m121.attachPop(m121PopCallback, &m121);

  b138.attachPop(b138PopCallback, &b138);
  bt131.attachPop(bt131PopCallback, &bt131);
  bt132.attachPop(bt132PopCallback, &bt132);
  bt133.attachPop(bt133PopCallback, &bt133);
  bt134.attachPop(bt134PopCallback, &bt134);
  bt135.attachPop(bt135PopCallback, &bt135);
  bt136.attachPop(bt136PopCallback, &bt136);

  m131.attachPop(m131PopCallback, &m131);
  m132.attachPop(m132PopCallback, &m132);
  m133.attachPop(m133PopCallback, &m133);
  m134.attachPop(m134PopCallback, &m134);
  m135.attachPop(m135PopCallback, &m135);
  m136.attachPop(m136PopCallback, &m136);

  m137.attachPop(m137PopCallback, &m137);
  m138.attachPop(m138PopCallback, &m138);

  n130.attachPop(n130PopCallback, &n130);
  n133.attachPop(n133PopCallback, &n133);
  n135.attachPop(n135PopCallback, &n135);
  n137.attachPop(n137PopCallback, &n137);
  n139.attachPop(n139PopCallback, &n139);
  n1311.attachPop(n1311PopCallback, &n1311);
  //n132.attachPop(n132PopCallback, &n132);
  //n134.attachPop(n134PopCallback, &n134);
  //n136.attachPop(n136PopCallback, &n136);
  //n138.attachPop(n138PopCallback, &n138);
  //n1310.attachPop(n1310PopCallback, &n1310);
  //n13112.attachPop(n1312PopCallback, &n1312);

  b140.attachPop(b140PopCallback, &b140);
  b148.attachPop(b148PopCallback, &b148);

}

void loop() {
  // put your main code here, to run repeatedly:
 if (PowerLightOn == true) {
    page12.show();
    n120.setValue(MaxLight1Value);
    n121.setValue(MaxLight2Value);
    n122.setValue(MaxLight3Value);

}


void bt10PopCallback(void *ptr) {

  if (digitalRead(37) == LOW) {

    bt10.setValue(0);
  }
  else if (digitalRead(37) == HIGH) {

    bt10.setValue(1);
  }
}
void bt11PopCallback(void *ptr) {

  if (digitalRead(53) == LOW) {

    bt11.setValue(0);
  }
  else if (digitalRead(53) == HIGH) {

    bt11.setValue(1);
  }
}
void bt12PopCallback(void *ptr) {

  if (digitalRead(45) == LOW) {

    bt12.setValue(0);
  }
  else if (digitalRead(45) == HIGH) {

    bt12.setValue(1);
  }
}

void b29PopCallback(void *ptr) {
  page11.show();


}
void m30PopCallback(void *ptr) {
  page2.show();

}
