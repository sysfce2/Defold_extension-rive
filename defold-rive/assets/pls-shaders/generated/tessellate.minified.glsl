#define ra 10
#ifdef VERTEX
V0(V)r0(0,g,GC);r0(1,g,HC);r0(2,g,ZB);r0(3,S,NB);W0
#endif
A1 l0 H(0,g,C3);l0 H(1,g,D3);l0 H(2,g,A2);l0 H(3,D1,c3);d6 H(4,uint,l4);B1 p v g8(d U0,d w0,d K0,d e1){v t;t[0]=(any(notEqual(U0,w0))?w0:any(notEqual(w0,K0))?K0:e1)-U0;t[1]=e1-(any(notEqual(e1,K0))?K0:any(notEqual(K0,w0))?w0:U0);return t;}
#ifdef VERTEX
O1 P1 V1 Q2(v7,A9,RB);Q2(w7,B9,FC);W1 float h8(d l,d b){float sa=dot(l,b);float i8=dot(l,l)*dot(b,b);return(i8==.0)?1.:clamp(sa*inversesqrt(i8),-1.,1.);}w1(UD,V,A,k,O){x0(O,A,GC,g);x0(O,A,HC,g);x0(O,A,ZB,g);x0(O,A,NB,S);P(C3,g);P(D3,g);P(A2,g);P(c3,D1);P(l4,uint);d U0=GC.xy;d w0=GC.zw;d K0=HC.xy;d e1=HC.zw;bool j8=k<4;float y=j8?ZB.z:ZB.w;int k8=int(j8?NB.x:NB.y);float m6=float(k8<<16>>16);float X4=float(k8>>16);d h1=d((k&1)==0?m6:X4,(k&2)==0?y+1.:y);uint r1=NB.z&0x3ffu;uint l8=(NB.z>>10)&0x3ffu;uint d3=NB.z>>20;uint D=NB.w;if(X4<m6){D|=I4;}if((X4-m6)*r.F5<.0){h1.y=2.*y+1.-h1.y;}if((D&o9)!=0u){uint ta=B0(FC,Y6(D)).z;v m8=X0(uintBitsToFloat(B0(RB,ta*2u)));d n8=i0(m8,-2.*w0+K0+U0);d o8=i0(m8,-2.*K0+e1+w0);float d1=max(dot(n8,n8),dot(o8,o8));float E2=max(ceil(sqrt(.75*4.*sqrt(d1))),1.);r1=min(uint(E2),r1);}uint Y4=r1+l8+d3-1u;v U1=g8(U0,w0,K0,e1);float o1=acos(h8(U1[0],U1[1]));float g2=o1/float(l8);float n6=determinant(v(K0-U0,e1-w0));if(n6==.0)n6=determinant(U1);if(n6<.0)g2=-g2;C3=g(U0,w0);D3=g(K0,e1);A2=g(float(Y4)-abs(X4-h1.x),float(Y4),(d3<<10)|r1,g2);if(d3>1u){v o6=v(U1[1],ZB.xy);float ua=acos(h8(o6[0],o6[1]));float p8=float(d3);if((D&(Z3|H4))==H4){p8-=2.;}float p6=ua/p8;if(determinant(o6)<.0)p6=-p6;c3.xy=ZB.xy;c3.z=p6;}l4=D;g B;B.x=h1.x*(2./n9)-1.;B.y=h1.y*r.F5-sign(r.F5);B.zw=d(0,1);R(C3);R(D3);R(A2);R(c3);R(l4);f1(B);}
#endif
#ifdef FRAGMENT
r2(S,VD){M(C3,g);M(D3,g);M(A2,g);M(c3,D1);M(l4,uint);d U0=C3.xy;d w0=C3.zw;d K0=D3.xy;d e1=D3.zw;v U1=g8(U0,w0,K0,e1);float va=max(floor(A2.x),.0);float Y4=A2.y;uint q8=uint(A2.z);float r1=float(q8&0x3ffu);float d3=float(q8>>10);float g2=A2.w;uint D=l4;float e3=Y4-d3;float v1=va;if(v1<=e3){D&=~Z3;}else{U0=w0=K0=e1;U1=v(U1[1],c3.xy);r1=1.;v1-=e3;e3=d3;if((D&Z3)!=0u){if(v1<2.5)D|=L5;if(v1>1.5&&v1<3.5)D|=m7;}else if((D&H4)!=0u){e3-=2.;v1--;}g2=c3.z;D|=g2<.0?J4:n7;}d Z4;float o1=.0;if(v1==.0||v1==e3||(D&Z3)!=0u){bool R4=v1<e3*.5;Z4=R4?U0:e1;o1=a7(R4?U1[0]:U1[1]);}else if((D&l7)!=0u){Z4=w0;}else{float T1,f3;if(r1==e3){T1=v1/r1;f3=.0;}else{d e0,h0,T4=w0-U0;d Y7=e1-U0;d r8=K0-w0;h0=r8-T4;e0=-3.*r8+Y7;d wa=h0*(r1*2.);d xa=T4*(r1*r1);float a5=.0;float ya=min(r1-1.,v1);d q6=normalize(U1[0]);float za=-abs(g2);float Aa=(1.+v1)*abs(g2);for(int G3=ra-1;G3>=0;--G3){float m4=a5+exp2(float(G3));if(m4<=ya){d r6=m4*e0+wa;r6=m4*r6+xa;float Ba=dot(normalize(r6),q6);float v6=m4*za+Aa;v6=min(v6,E4);if(Ba>=cos(v6))a5=m4;}}float Ca=a5/r1;float v8=v1-a5;float c5=acos(clamp(q6.x,-1.,1.));c5=q6.y>=.0?c5:-c5;o1=v8*g2+c5;d T2=d(sin(o1),-cos(o1));float l=dot(T2,e0),d5=dot(T2,h0),g0=dot(T2,T4);float Da=max(d5*d5-l*g0,.0);float B2=sqrt(Da);if(d5>.0)B2=-B2;B2-=d5;float w8=-.5*B2*l;d w6=(abs(B2*B2+w8)<abs(l*g0+w8))?d(B2,l):d(g0,B2);f3=(w6.y!=.0)?w6.x/w6.y:.0;f3=clamp(f3,.0,1.);if(v8==.0)f3=.0;T1=max(Ca,f3);}d Ea=p3(U0,w0,T1);d x8=p3(w0,K0,T1);d Fa=p3(K0,e1,T1);d y8=p3(Ea,x8,T1);d z8=p3(x8,Fa,T1);Z4=p3(y8,z8,T1);if(T1!=f3)o1=a7(z8-y8);}v2(S(floatBitsToUint(D1(Z4,o1)),D));}
#endif
