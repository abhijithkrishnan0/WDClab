clc;clear all;close all;
N=5;
m=10^6;
ip=rand(1,m)>0.5;
BPSK=2*ip-1;
L=2;
snr_dB=1:1:15;
snr=10.^(snr_dB/10);
P_R_MRC=(1/2)-(1/2).*(1+1./snr).^(-1/2);
BER_MRC_ana=(P_R_MRC).^2.*(1+2.*(1-P_R_MRC));

n_err=zeros(1,length(snr_dB));

for p=1:N
    for q=1:length(snr_dB)
        N0=(1/sqrt(2)).*(randn(L,m)+1j*(randn(L,m)));
        h=(1/sqrt(2)).*(randn(L,m)+1j*(randn(L,m)));
        symbol=kron(ones(L,1),BPSK);
        rec_vec=symbol.*h+10.^(-snr_dB(q)/20)*N0;
        dec_metric=sum(conj(h).*rec_vec,1)./sum(conj(h).*h,1);
        ip_hat=real(dec_metric)>0;
        n_err(q)=n_err(q)+size(find([ip-ip_hat]),2);
    end
end
ber_MRC_sim=n_err/(N*m);
semilogy(snr_dB,ber_MRC_sim,'or','LineWidth',2);
semilogy(snr_dB,ber_MRC_ana,'-or','LineWidth',2);