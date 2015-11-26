num1 = [0.01031 0.06188 0.1547 0.2063 0.1547 0.06188 0.01031]; % Den oprindelige tæller til overføringsfunktionen

den1 = [1 -1.188 1.305 -0.6743 0.2635 -0.05175 0.005023]; % Den oprindelige nævner til overføringsfunktionen
denImp = [1 -1.188 1.305 -0.6743 0.2635 -0.05175 0.005023 0]; % Den nye nævner til at finde impulsrespons
denStep = [1 -2.188 2.493 -1.9793 0.9378 -0.3153 0.05677 -0.005023]; %Den nye nævner til at finde steprespons

num2 = [0.01031 0.06188 0.1547 0.2063 0.1547 0.06188 0.01031 0];

H1 = tf(num1,den1);
H2 = tf(num1,denImp);
H3 = tf(num1,denStep);

z1 = zero(H1)
p1 = pole(H1)
p2 = pole(H2)
p3 = pole(H3)
%% opgave 3
w = 0:0.01:pi;
r1 = polyval(num1,exp(j*w));
r2 = polyval(den1,exp(j*w));
mag = abs(r1./r2);
pha = angle(r1./r2);
magdb = mag2db(mag);

figure(1)
subplot(2,1,1)
plot(magdb)
xlabel('Magnitude Response')
ylabel('[dB]')

subplot(2,1,2)
plot(pha)
xlabel('Phase Response')
ylabel('Radians')
%% opgave 4

[SOS, G] = tf2sos(num1,den1);

fvtool(SOS,G)
%% H1
figure(1)
pzmap(H1)
xlim([-2 2]);
ylim([-2 2]);
viscircles([0 0],1)

%% H2

figure(2)
pzmap(H2)
xlim([-2 2]);
ylim([-2 2]);
viscircles([0 0],1)

%% H3

figure(3)
pzmap(H3)
xlim([-2 2]);
ylim([-2 2]);
viscircles([0 0],1)

%% 


[r p k] = residue(num1,denImp)


%%
figure(1)
n = 1:1:40;
y = 2*abs(r(1))*power(abs(p(1)),n).*cos(n*angle(p(1))+angle(r(1)))+2*abs(r(3))*power(abs(p(3)),n).*cos(n*angle(p(3))+angle(r(3)))+2*abs(r(5))*power(abs(p(5)),n).*cos(n*angle(p(5))+angle(r(5)));

stem(n,y)
xlabel('Impulsrespons ud fra partialbrøker')

%%
figure(2)
stepz(num1,den1)


%%
figure(4)
bode(H1)

%%

figure(5)
step(H1)

%%

