#include <SoftwareSerial.h>

#include <DFRobotDFPlayerMini.h>

SoftwareSerial mySerial(10, 11); // RX, TX

DFRobotDFPlayerMini myDFPlayer;

void setup()

{

  mySerial.begin(9600); // setelah modul SR digunakan

  Serial.begin(9600);

  myDFPlayer.begin(mySerial);

  myDFPlayer.volume(30);

  myDFPlayer.play(1);

}

void loop()

{

  String input = ""; // variabel untuk menampung input suara

  while(Serial.available()){

    char c = Serial.read();

    input += c;

  }

  if(input != ""){

    Serial.println(input); // menampilkan input suara pada Serial Monitor

    if(input.indexOf("tambah") >= 0){

      int angka1 = 2;

      int angka2 = 3;

      int hasil = angka1 + angka2;

      Serial.print("Hasil: ");

      Serial.println(hasil); // menampilkan hasil operasi pada Serial Monitor

      myDFPlayer.play(2); // memutar suara untuk menampilkan hasil

    }

    else if(input.indexOf("kurang") >= 0){

      int angka1 = 5;

      int angka2 = 3;

      int hasil = angka1 - angka2;

      Serial.print("Hasil: ");

      Serial.println(hasil); // menampilkan hasil operasi pada Serial Monitor

      myDFPlayer.play(2); // memutar suara untuk menampilkan hasil

    }

    else if(input.indexOf("kali") >= 0){

      int angka1 = 2;

      int angka2 = 3;

      int hasil = angka1 * angka2;

      Serial.print("Hasil: ");

      Serial.println(hasil); // menampilkan hasil operasi pada Serial Monitor

      myDFPlayer.play(2); // memutar suara untuk menampilkan hasil

    }

    else if(input.indexOf("bagi") >= 0){

      int angka1 = 6;

      int angka2 = 3;

      int hasil = angka1 / angka2;

      Serial.print("Hasil: ");

      Serial.println(hasil); // menampilkan hasil operasi pada Serial Monitor

myDFPlayer.play(2); // memutar suara untuk menampilkan hasil

}

else{

Serial.println("Perintah tidak dikenali"); // menampilkan pesan jika perintah tidak dikenali

myDFPlayer.play(3); // memutar suara untuk menampilkan pesan error

}

}

}
