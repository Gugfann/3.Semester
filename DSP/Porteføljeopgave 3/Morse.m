clear;

dataIn = audioread('morse.wav');
Fs = 44100;
Fnyquist = Fs/2;
N = length(dataIn);

%% Frequency content of input signal

dF = Fs/N;                      % hertz
f = -Fs/2:dF:Fs/2-dF;           % hertz
X = abs(fftshift(fft(dataIn)));
   
plot(f,abs(X));
   
xlim([0,Fnyquist])

%% Highpass Filter (Butterworth)

Fpass = 1085;
Fstop = 1060;

wPass = Fpass/Fnyquist;
wStop = Fstop/Fnyquist;

[n, Wn] = buttord(wPass,wStop,3,50);

[z,p,k] = butter(n,Wn,'high');
sos = zp2sos(z,p,k);

hfvt = fvtool(sos);
legend(hfvt,'ZPK Design')

%freqz(sos,3000,44100);

dataOut = sosfilt(sos,dataIn);

%soundsc(dataOut,Fs)


%% Bandpass Filter (Butterworth)
Fcenter = 1093; 
dPass = 12;
dStop = 15;
Fpass = [Fcenter-dPass Fcenter+dPass];
Fstop = [Fcenter-dStop Fcenter+dStop];

wPass = Fpass/Fnyquist;
wStop = Fstop/Fnyquist;

[n, Wn] = buttord(wPass,wStop,3,50);

[z,p,k] = butter(n,Wn,'bandpass');
sos = zp2sos(z,p,k);

hfvt = fvtool(sos);
legend(hfvt,'ZPK Design')

%freqz(sos,3000,44100);

dataOut = sosfilt(sos,dataIn);

%soundsc(dataOut,Fs)

%% Before/After plots of filtering in both time- and frequency domain

Xin = fftshift(fft(dataIn));
Xout = fftshift(fft(dataOut));
%N = length(dataIn);
dF = Fs/N;                      % hertz
f = -Fs/2:dF:Fs/2-dF;           % hertz

figure(1)

subplot(2,1,1)
plot(dataIn)
xlabel('Before')
title('Time domain')

subplot(2,1,2)
plot(dataOut)
xlabel('After')
figure(2)

subplot(2,1,1)
plot(f,abs(Xin))
xlabel('Before')
title('Frequency domain')
xlim([0,Fnyquist])

subplot(2,1,2)
plot(f,abs(Xout))
xlabel('After')
xlim([0,Fnyquist])