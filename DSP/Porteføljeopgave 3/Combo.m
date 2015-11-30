clear;
clc;

dataIn = audioread('morse.wav');
Fs = 44100;
T = 1/Fs;
Fnyquist = Fs/2;

Fc = 1100;

N = 101;

n = 0:1:(N-1);
M = (N-1)/2;

omegaC = 2*pi*Fc/Fs;
%%

himp = sin(omegaC*(n-M))./((n-M)*pi);
himp(M+1) = omegaC / pi;

% Hanning window
hanning = 0.5 + 0.5*cos(pi*(n-M)/M);

hwindow = himp.*hanning;

figure(1)
freqz(himp)
figure(2)
freqz(hwindow)

%%
test=conv(dataIn,hwindow);

N1 = length(dataIn);
dF = Fs/N1;                      % hertz
f1 = -Fs/2:dF:Fs/2-dF;           % hertz

N2 = length(test);
dF = Fs/N2;                      % hertz
f2 = -Fs/2:dF:Fs/2-dF;           % hertz
X = abs(fftshift(fft(test)));

figure(2)
plot(f2,X);
  
xlim([0,Fnyquist])

%soundsc(test,Fs)

%plot(test)

%% Combo

Fpass = 1085;
Fstop = 1060;

wdPass = 2*pi*Fpass;
wdStop = 2*pi*Fstop;

wPass = Fpass/Fnyquist;
wStop = Fstop/Fnyquist;

[n, Wn] = buttord(wPass,wStop,3,50);

[z,p,k] = butter(n,Wn,'high');
sos = zp2sos(z,p,k);

dataOut = sosfilt(sos,test);
soundsc(dataOut,Fs)

%audiowrite('filter.wav',dataOut,Fs)

%% Frequency spectrum after filtering

N3 = length(dataOut);
dF = Fs/N3;                      % hertz
f3 = -Fs/2:dF:Fs/2-dF;           % hertz
X = abs(fftshift(fft(dataOut)));

figure(3)
plot(f3,X);
   
xlim([0,Fnyquist])

%% Before/After plots of filtering in both time- and frequency domain

Xin = fftshift(fft(dataIn));
Xtest = fftshift(fft(test));
Xout = fftshift(fft(dataOut));

figure(4)

subplot(3,1,1)
plot(dataIn)
xlabel('Before')
title('Time domain')

subplot(3,1,2)
plot(test)
xlabel('1st Filter')

subplot(3,1,3)
plot(dataOut)
xlabel('After')

%%
figure(5)
subplot(3,1,1)
plot(f1,mag2db(abs(Xin)))
xlabel('Before')
title('Frequency domain')
xlim([0,Fnyquist])

subplot(3,1,2)
plot(f2,mag2db(abs(Xtest)))
xlabel('1st Filter')
xlim([0,Fnyquist])

subplot(3,1,3)
plot(f3,mag2db(abs(Xout)))
xlabel('After')
xlim([0,Fnyquist])

%%
figure(10)
plot(dataOut)
xlabel('After')