.name       "UltraKillerLord"
.comment    "Ultrakilling you"

fork	%:live1
wall:
    st  r4, -254
    st  r4, -12
    st  r4, -260
    st  r4, -26
    st  r4, -266
    st  r4, -40
    st  r4, -272
    st  r4, -54
    st  r4, -278
    st  r4, -68
    st  r4, -284
    st  r4, -82
    st  r4, -290
    st  r4, -96
    st  r4, -296
    st  r4, -110
    st  r4, -302
    st  r4, -124
    st  r4, -308
    st  r4, -138
    st  r4, -314
    st  r4, -152
    st  r4, -320
    st  r4, -166
    st  r4, -326
    st  r4, -180
    st  r4, -332
    st  r4, -194
    st  r4, -338
    st  r4, -208
    st  r4, -344
    st  r4, -222
    st  r4, -350
    st  r4, -236
    st  r4, -356
    st  r4, -250
    st  r4, -362
    st  r4, -264
    st  r4, -368
    st  r4, -278
    st  r4, -374
    st  r4, -292
    st  r4, -380
    st  r4, -306
    st  r4, -386
    st  r4, -320
    st  r4, -392
    st  r4, -334
    st  r4, -398
    st  r4, -348
    st  r4, -404
    st  r4, -362
    st  r4, -410
    st  r4, -376
    st  r4, -416
    st  r4, -390
    st  r4, -422
    st  r4, -404
    st  r4, -428
    st  r4, -418
    st  r4, -434
    st  r4, -432
    st  r4, -440
    st  r1, 6
    live   %0

    fork %:wall
    st  r1, 6
    live   %0

    fork %:live1
    st  r1, 6
    live   %0
    fork %:live2
    add r4, r4, r4
    zjmp %:wall

live1:
    st  r1, 6
    live    %0
    add r4, r4, r4
    zjmp %:live1

live2:
    st  r1, 6
    live    %0
    fork %:wall
    fork %:attack
    fork %:live3
    fork %:live4
    add r4, r4, r4
    zjmp %:live2

live3:
    st  r1, 6
    live    %0
    add r4, r4, r4
    zjmp %:live3

live4:
    st  r1, 6
    live    %0
    fork %:wall
    fork %:live5
    fork %:live6
    add r4, r4, r4
    zjmp %:live4

live5:
    st  r1, 6
    live    %0
    add r4, r4, r4
    zjmp %:live5

live6:
    st  r1, 6
    live    %0
    fork %:wall
    fork %:live7
    add r4, r4, r4
    zjmp %:live6

live7:
    st  r1, 6
    live    %0
    add r4, r4, r4
    zjmp %:live7

attack:

ld %89, r10
aff r10
ld %111, r10
aff r10
ld %117, r10
aff r10
ld %32, r10
aff r10
ld %108, r10
aff r10
ld %111, r10
aff r10
ld %115, r10
aff r10
ld %101, r10
aff r10
add r4, r4, r4
st r1, 6
superlive:
live %0
zjmp %:superlive
