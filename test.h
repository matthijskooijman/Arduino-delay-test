void delayMicroseconds(uint16_t usec)
{
}

// This needs always_inline to ensure any constant argument reaches delayMicroseconds
static inline void measure_one(Results&, uint16_t) __attribute__((__always_inline__));
static inline void measure_one(Results& results, uint16_t us) {
  // Clear overflow flag
  TCNT1 = 0;
  TIFR1 = (1 << TOV1);
  uint16_t start, end;
  // Access TCNT1 using assembly, so we can guarantee to know the exact overhead
  asm volatile (
    "lds %A0, %1\n"
    "lds %B0, %2\n"
    : "=w" (start)
    : "M" (_SFR_MEM_ADDR(TCNT1L)),
      "M" (_SFR_MEM_ADDR(TCNT1H))
  );
  
  delayMicroseconds(us);
  
  asm volatile (
    "lds %A0, %1\n"
    "lds %B0, %2\n"
    : "=w" (end)
    : "M" (_SFR_MEM_ADDR(TCNT1L)),
      "M" (_SFR_MEM_ADDR(TCNT1H))
  );
  process_results(results, us, start, end, TIFR1 & (1 << TOV1), F_CPU / 1000000);
}

static void measure_range(Results& results, uint16_t from, const uint16_t to, const uint16_t step = 1) {
  while (from <= to) {
    measure_one(results, from);
    from += step;
  }
}

static void measure_all(Results& results) {
  Serial.print(">> Constants @");
  Serial.print(F_CPU / 1000000);
  Serial.println("Mhz");
  
  // Generated using bash:
  // for i in {0..100}; do echo "measure_one(results, $i);"; done
  // for i in {101..1000..7}; do echo "measure_one(results, $i);"; done
  // To save time and space, does not test all values, but instead skips a prime
  // number every time, hoping to at least test some corner cases too.
  measure_one(results, 0);
  measure_one(results, 1);
  measure_one(results, 2);
  measure_one(results, 3);
  measure_one(results, 4);
  measure_one(results, 5);
  measure_one(results, 6);
  measure_one(results, 7);
  measure_one(results, 8);
  measure_one(results, 9);
  measure_one(results, 10);
  measure_one(results, 11);
  measure_one(results, 12);
  measure_one(results, 13);
  measure_one(results, 14);
  measure_one(results, 15);
  measure_one(results, 16);
  measure_one(results, 17);
  measure_one(results, 18);
  measure_one(results, 19);
  measure_one(results, 20);
  measure_one(results, 21);
  measure_one(results, 22);
  measure_one(results, 23);
  measure_one(results, 24);
  measure_one(results, 25);
  measure_one(results, 26);
  measure_one(results, 27);
  measure_one(results, 28);
  measure_one(results, 29);
  measure_one(results, 30);
  measure_one(results, 31);
  measure_one(results, 32);
  measure_one(results, 33);
  measure_one(results, 34);
  measure_one(results, 35);
  measure_one(results, 36);
  measure_one(results, 37);
  measure_one(results, 38);
  measure_one(results, 39);
  measure_one(results, 40);
  measure_one(results, 41);
  measure_one(results, 42);
  measure_one(results, 43);
  measure_one(results, 44);
  measure_one(results, 45);
  measure_one(results, 46);
  measure_one(results, 47);
  measure_one(results, 48);
  measure_one(results, 49);
  measure_one(results, 50);
  measure_one(results, 51);
  measure_one(results, 52);
  measure_one(results, 53);
  measure_one(results, 54);
  measure_one(results, 55);
  measure_one(results, 56);
  measure_one(results, 57);
  measure_one(results, 58);
  measure_one(results, 59);
  measure_one(results, 60);
  measure_one(results, 61);
  measure_one(results, 62);
  measure_one(results, 63);
  measure_one(results, 64);
  measure_one(results, 65);
  measure_one(results, 66);
  measure_one(results, 67);
  measure_one(results, 68);
  measure_one(results, 69);
  measure_one(results, 70);
  measure_one(results, 71);
  measure_one(results, 72);
  measure_one(results, 73);
  measure_one(results, 74);
  measure_one(results, 75);
  measure_one(results, 76);
  measure_one(results, 77);
  measure_one(results, 78);
  measure_one(results, 79);
  measure_one(results, 80);
  measure_one(results, 81);
  measure_one(results, 82);
  measure_one(results, 83);
  measure_one(results, 84);
  measure_one(results, 85);
  measure_one(results, 86);
  measure_one(results, 87);
  measure_one(results, 88);
  measure_one(results, 89);
  measure_one(results, 90);
  measure_one(results, 91);
  measure_one(results, 92);
  measure_one(results, 93);
  measure_one(results, 94);
  measure_one(results, 95);
  measure_one(results, 96);
  measure_one(results, 97);
  measure_one(results, 98);
  measure_one(results, 99);
  measure_one(results, 100);
  measure_one(results, 101);
  measure_one(results, 108);
  measure_one(results, 115);
  measure_one(results, 122);
  measure_one(results, 129);
  measure_one(results, 136);
  measure_one(results, 143);
  measure_one(results, 150);
  measure_one(results, 157);
  measure_one(results, 164);
  measure_one(results, 171);
  measure_one(results, 178);
  measure_one(results, 185);
  measure_one(results, 192);
  measure_one(results, 199);
  measure_one(results, 206);
  measure_one(results, 213);
  measure_one(results, 220);
  measure_one(results, 227);
  measure_one(results, 234);
  measure_one(results, 241);
  measure_one(results, 248);
  measure_one(results, 255);
  measure_one(results, 262);
  measure_one(results, 269);
  measure_one(results, 276);
  measure_one(results, 283);
  measure_one(results, 290);
  measure_one(results, 297);
  measure_one(results, 304);
  measure_one(results, 311);
  measure_one(results, 318);
  measure_one(results, 325);
  measure_one(results, 332);
  measure_one(results, 339);
  measure_one(results, 346);
  measure_one(results, 353);
  measure_one(results, 360);
  measure_one(results, 367);
  measure_one(results, 374);
  measure_one(results, 381);
  measure_one(results, 388);
  measure_one(results, 395);
  measure_one(results, 402);
  measure_one(results, 409);
  measure_one(results, 416);
  measure_one(results, 423);
  measure_one(results, 430);
  measure_one(results, 437);
  measure_one(results, 444);
  measure_one(results, 451);
  measure_one(results, 458);
  measure_one(results, 465);
  measure_one(results, 472);
  measure_one(results, 479);
  measure_one(results, 486);
  measure_one(results, 493);
  measure_one(results, 500);
  measure_one(results, 507);
  measure_one(results, 514);
  measure_one(results, 521);
  measure_one(results, 528);
  measure_one(results, 535);
  measure_one(results, 542);
  measure_one(results, 549);
  measure_one(results, 556);
  measure_one(results, 563);
  measure_one(results, 570);
  measure_one(results, 577);
  measure_one(results, 584);
  measure_one(results, 591);
  measure_one(results, 598);
  measure_one(results, 605);
  measure_one(results, 612);
  measure_one(results, 619);
  measure_one(results, 626);
  measure_one(results, 633);
  measure_one(results, 640);
  measure_one(results, 647);
  measure_one(results, 654);
  measure_one(results, 661);
  measure_one(results, 668);
  measure_one(results, 675);
  measure_one(results, 682);
  measure_one(results, 689);
  measure_one(results, 696);
  measure_one(results, 703);
  measure_one(results, 710);
  measure_one(results, 717);
  measure_one(results, 724);
  measure_one(results, 731);
  measure_one(results, 738);
  measure_one(results, 745);
  measure_one(results, 752);
  measure_one(results, 759);
  measure_one(results, 766);
  measure_one(results, 773);
  measure_one(results, 780);
  measure_one(results, 787);
  measure_one(results, 794);
  measure_one(results, 801);
  measure_one(results, 808);
  measure_one(results, 815);
  measure_one(results, 822);
  measure_one(results, 829);
  measure_one(results, 836);
  measure_one(results, 843);
  measure_one(results, 850);
  measure_one(results, 857);
  measure_one(results, 864);
  measure_one(results, 871);
  measure_one(results, 878);
  measure_one(results, 885);
  measure_one(results, 892);
  measure_one(results, 899);
  measure_one(results, 906);
  measure_one(results, 913);
  measure_one(results, 920);
  measure_one(results, 927);
  measure_one(results, 934);
  measure_one(results, 941);
  measure_one(results, 948);
  measure_one(results, 955);
  measure_one(results, 962);
  measure_one(results, 969);
  measure_one(results, 976);
  measure_one(results, 983);
  measure_one(results, 990);
  measure_one(results, 997);
  measure_one(results, 1001);
  measure_one(results, 1098);
  measure_one(results, 1195);
  measure_one(results, 1292);
  measure_one(results, 1389);
  measure_one(results, 1486);
  measure_one(results, 1583);
  measure_one(results, 1680);
  measure_one(results, 1777);
  measure_one(results, 1874);
  measure_one(results, 1971);
  measure_one(results, 2068);
  measure_one(results, 2165);
  measure_one(results, 2262);
  measure_one(results, 2359);
  measure_one(results, 2456);
  measure_one(results, 2553);
  measure_one(results, 2650);
  measure_one(results, 2747);
  measure_one(results, 2844);
  measure_one(results, 2941);
  measure_one(results, 3038);
  measure_one(results, 3135);
  measure_one(results, 3232);
  measure_one(results, 3329);
  measure_one(results, 3426);
  measure_one(results, 3523);
  measure_one(results, 3620);
  measure_one(results, 3717);
  measure_one(results, 3814);
  measure_one(results, 3911);
  measure_one(results, 4008);
  measure_one(results, 4105);
  measure_one(results, 4202);
  measure_one(results, 4299);
  measure_one(results, 4396);
  measure_one(results, 4493);
  measure_one(results, 4590);
  measure_one(results, 4687);
  measure_one(results, 4784);
  measure_one(results, 4881);
  measure_one(results, 4978);
  measure_one(results, 5075);
  measure_one(results, 5172);
  measure_one(results, 5269);
  measure_one(results, 5366);
  measure_one(results, 5463);
  measure_one(results, 5560);
  measure_one(results, 5657);
  measure_one(results, 5754);
  measure_one(results, 5851);
  measure_one(results, 5948);
  measure_one(results, 6045);
  measure_one(results, 6142);
  measure_one(results, 6239);
  measure_one(results, 6336);
  measure_one(results, 6433);
  measure_one(results, 6530);
  measure_one(results, 6627);
  measure_one(results, 6724);
  measure_one(results, 6821);
  measure_one(results, 6918);
  measure_one(results, 7015);
  measure_one(results, 7112);
  measure_one(results, 7209);
  measure_one(results, 7306);
  measure_one(results, 7403);
  measure_one(results, 7500);
  measure_one(results, 7597);
  measure_one(results, 7694);
  measure_one(results, 7791);
  measure_one(results, 7888);
  measure_one(results, 7985);
  measure_one(results, 8082);
  measure_one(results, 8179);
  measure_one(results, 8276);
  measure_one(results, 8373);
  measure_one(results, 8470);
  measure_one(results, 8567);
  measure_one(results, 8664);
  measure_one(results, 8761);
  measure_one(results, 8858);
  measure_one(results, 8955);
  measure_one(results, 9052);
  measure_one(results, 9149);
  measure_one(results, 9246);
  measure_one(results, 9343);
  measure_one(results, 9440);
  measure_one(results, 9537);
  measure_one(results, 9634);
  measure_one(results, 9731);
  measure_one(results, 9828);
  measure_one(results, 9925);

  Serial.print(">> Variables @");
  Serial.print(F_CPU / 1000000);
  Serial.println("Mhz");
  measure_range(results, 0, 100);
  measure_range(results, 101, 1000, 7);
  measure_range(results, 1001, 10000, 97);

  results.f_cpu = F_CPU;
}

