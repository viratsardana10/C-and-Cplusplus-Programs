
a.exe:     file format pei-i386

Disassembly of section .text:

00401000 <___crt_xc_end__>:
  401000:	55                   	push   %ebp
  401001:	89 e5                	mov    %esp,%ebp
  401003:	83 ec 18             	sub    $0x18,%esp
  401006:	89 5d f8             	mov    %ebx,0xfffffff8(%ebp)
  401009:	8b 55 08             	mov    0x8(%ebp),%edx
  40100c:	31 db                	xor    %ebx,%ebx
  40100e:	89 75 fc             	mov    %esi,0xfffffffc(%ebp)
  401011:	8b 02                	mov    (%edx),%eax
  401013:	31 f6                	xor    %esi,%esi
  401015:	8b 00                	mov    (%eax),%eax
  401017:	3d 91 00 00 c0       	cmp    $0xc0000091,%eax
  40101c:	77 43                	ja     401061 <___crt_xc_end__+0x61>
  40101e:	3d 8d 00 00 c0       	cmp    $0xc000008d,%eax
  401023:	72 5b                	jb     401080 <___crt_xc_end__+0x80>
  401025:	be 01 00 00 00       	mov    $0x1,%esi
  40102a:	c7 04 24 08 00 00 00 	movl   $0x8,(%esp)
  401031:	31 c0                	xor    %eax,%eax
  401033:	89 44 24 04          	mov    %eax,0x4(%esp)
  401037:	e8 b4 08 00 00       	call   4018f0 <_signal>
  40103c:	83 f8 01             	cmp    $0x1,%eax
  40103f:	74 6c                	je     4010ad <___crt_xc_end__+0xad>
  401041:	85 c0                	test   %eax,%eax
  401043:	74 2a                	je     40106f <___crt_xc_end__+0x6f>
  401045:	c7 04 24 08 00 00 00 	movl   $0x8,(%esp)
  40104c:	ff d0                	call   *%eax
  40104e:	bb ff ff ff ff       	mov    $0xffffffff,%ebx
  401053:	89 d8                	mov    %ebx,%eax
  401055:	8b 75 fc             	mov    0xfffffffc(%ebp),%esi
  401058:	8b 5d f8             	mov    0xfffffff8(%ebp),%ebx
  40105b:	89 ec                	mov    %ebp,%esp
  40105d:	5d                   	pop    %ebp
  40105e:	c2 04 00             	ret    $0x4
  401061:	3d 93 00 00 c0       	cmp    $0xc0000093,%eax
  401066:	74 bd                	je     401025 <___crt_xc_end__+0x25>
  401068:	3d 94 00 00 c0       	cmp    $0xc0000094,%eax
  40106d:	74 bb                	je     40102a <___crt_xc_end__+0x2a>
  40106f:	89 d8                	mov    %ebx,%eax
  401071:	8b 75 fc             	mov    0xfffffffc(%ebp),%esi
  401074:	8b 5d f8             	mov    0xfffffff8(%ebp),%ebx
  401077:	89 ec                	mov    %ebp,%esp
  401079:	5d                   	pop    %ebp
  40107a:	c2 04 00             	ret    $0x4
  40107d:	8d 76 00             	lea    0x0(%esi),%esi
  401080:	3d 05 00 00 c0       	cmp    $0xc0000005,%eax
  401085:	75 e8                	jne    40106f <___crt_xc_end__+0x6f>
  401087:	c7 04 24 0b 00 00 00 	movl   $0xb,(%esp)
  40108e:	31 f6                	xor    %esi,%esi
  401090:	89 74 24 04          	mov    %esi,0x4(%esp)
  401094:	e8 57 08 00 00       	call   4018f0 <_signal>
  401099:	83 f8 01             	cmp    $0x1,%eax
  40109c:	74 34                	je     4010d2 <___crt_xc_end__+0xd2>
  40109e:	85 c0                	test   %eax,%eax
  4010a0:	74 cd                	je     40106f <___crt_xc_end__+0x6f>
  4010a2:	c7 04 24 0b 00 00 00 	movl   $0xb,(%esp)
  4010a9:	ff d0                	call   *%eax
  4010ab:	eb a1                	jmp    40104e <___crt_xc_end__+0x4e>
  4010ad:	c7 04 24 08 00 00 00 	movl   $0x8,(%esp)
  4010b4:	bb 01 00 00 00       	mov    $0x1,%ebx
  4010b9:	89 5c 24 04          	mov    %ebx,0x4(%esp)
  4010bd:	e8 2e 08 00 00       	call   4018f0 <_signal>
  4010c2:	85 f6                	test   %esi,%esi
  4010c4:	74 88                	je     40104e <___crt_xc_end__+0x4e>
  4010c6:	e8 65 03 00 00       	call   401430 <__fpreset>
  4010cb:	bb ff ff ff ff       	mov    $0xffffffff,%ebx
  4010d0:	eb 81                	jmp    401053 <___crt_xc_end__+0x53>
  4010d2:	c7 04 24 0b 00 00 00 	movl   $0xb,(%esp)
  4010d9:	b9 01 00 00 00       	mov    $0x1,%ecx
  4010de:	bb ff ff ff ff       	mov    $0xffffffff,%ebx
  4010e3:	89 4c 24 04          	mov    %ecx,0x4(%esp)
  4010e7:	e8 04 08 00 00       	call   4018f0 <_signal>
  4010ec:	e9 62 ff ff ff       	jmp    401053 <___crt_xc_end__+0x53>
  4010f1:	eb 0d                	jmp    401100 <___mingw_CRTStartup>
  4010f3:	90                   	nop    
  4010f4:	90                   	nop    
  4010f5:	90                   	nop    
  4010f6:	90                   	nop    
  4010f7:	90                   	nop    
  4010f8:	90                   	nop    
  4010f9:	90                   	nop    
  4010fa:	90                   	nop    
  4010fb:	90                   	nop    
  4010fc:	90                   	nop    
  4010fd:	90                   	nop    
  4010fe:	90                   	nop    
  4010ff:	90                   	nop    

00401100 <___mingw_CRTStartup>:
  401100:	55                   	push   %ebp
  401101:	89 e5                	mov    %esp,%ebp
  401103:	53                   	push   %ebx
  401104:	83 ec 24             	sub    $0x24,%esp
  401107:	8d 5d f8             	lea    0xfffffff8(%ebp),%ebx
  40110a:	c7 04 24 00 10 40 00 	movl   $0x401000,(%esp)
  401111:	e8 9a 08 00 00       	call   4019b0 <_SetUnhandledExceptionFilter@4>
  401116:	83 ec 04             	sub    $0x4,%esp
  401119:	e8 12 03 00 00       	call   401430 <__fpreset>
  40111e:	c7 45 f8 00 00 00 00 	movl   $0x0,0xfffffff8(%ebp)
  401125:	b8 00 40 40 00       	mov    $0x404000,%eax
  40112a:	8d 55 f4             	lea    0xfffffff4(%ebp),%edx
  40112d:	89 5c 24 10          	mov    %ebx,0x10(%esp)
  401131:	8b 0d 00 20 40 00    	mov    0x402000,%ecx
  401137:	89 44 24 04          	mov    %eax,0x4(%esp)
  40113b:	89 54 24 08          	mov    %edx,0x8(%esp)
  40113f:	89 4c 24 0c          	mov    %ecx,0xc(%esp)
  401143:	c7 04 24 04 40 40 00 	movl   $0x404004,(%esp)
  40114a:	e8 d1 07 00 00       	call   401920 <___getmainargs>
  40114f:	a1 10 40 40 00       	mov    0x404010,%eax
  401154:	85 c0                	test   %eax,%eax
  401156:	74 58                	je     4011b0 <___mingw_CRTStartup+0xb0>
  401158:	a3 10 20 40 00       	mov    %eax,0x402010
  40115d:	8b 15 e0 50 40 00    	mov    0x4050e0,%edx
  401163:	85 d2                	test   %edx,%edx
  401165:	0f 85 8b 00 00 00    	jne    4011f6 <___mingw_CRTStartup+0xf6>
  40116b:	83 fa e0             	cmp    $0xffffffe0,%edx
  40116e:	74 20                	je     401190 <___mingw_CRTStartup+0x90>
  401170:	a1 10 40 40 00       	mov    0x404010,%eax
  401175:	89 44 24 04          	mov    %eax,0x4(%esp)
  401179:	8b 1d e0 50 40 00    	mov    0x4050e0,%ebx
  40117f:	8b 4b 30             	mov    0x30(%ebx),%ecx
  401182:	89 0c 24             	mov    %ecx,(%esp)
  401185:	e8 86 07 00 00       	call   401910 <__setmode>
  40118a:	8b 15 e0 50 40 00    	mov    0x4050e0,%edx
  401190:	83 fa c0             	cmp    $0xffffffc0,%edx
  401193:	74 1b                	je     4011b0 <___mingw_CRTStartup+0xb0>
  401195:	8b 1d 10 40 40 00    	mov    0x404010,%ebx
  40119b:	89 5c 24 04          	mov    %ebx,0x4(%esp)
  40119f:	8b 0d e0 50 40 00    	mov    0x4050e0,%ecx
  4011a5:	8b 51 50             	mov    0x50(%ecx),%edx
  4011a8:	89 14 24             	mov    %edx,(%esp)
  4011ab:	e8 60 07 00 00       	call   401910 <__setmode>
  4011b0:	e8 4b 07 00 00       	call   401900 <___p__fmode>
  4011b5:	8b 1d 10 20 40 00    	mov    0x402010,%ebx
  4011bb:	89 18                	mov    %ebx,(%eax)
  4011bd:	e8 3e 02 00 00       	call   401400 <__pei386_runtime_relocator>
  4011c2:	83 e4 f0             	and    $0xfffffff0,%esp
  4011c5:	e8 16 07 00 00       	call   4018e0 <___p__environ>
  4011ca:	8b 08                	mov    (%eax),%ecx
  4011cc:	89 4c 24 08          	mov    %ecx,0x8(%esp)
  4011d0:	8b 15 00 40 40 00    	mov    0x404000,%edx
  4011d6:	89 54 24 04          	mov    %edx,0x4(%esp)
  4011da:	a1 04 40 40 00       	mov    0x404004,%eax
  4011df:	89 04 24             	mov    %eax,(%esp)
  4011e2:	e8 b7 01 00 00       	call   40139e <_main>
  4011e7:	89 c3                	mov    %eax,%ebx
  4011e9:	e8 e2 06 00 00       	call   4018d0 <__cexit>
  4011ee:	89 1c 24             	mov    %ebx,(%esp)
  4011f1:	e8 ca 07 00 00       	call   4019c0 <_ExitProcess@4>
  4011f6:	89 44 24 04          	mov    %eax,0x4(%esp)
  4011fa:	8b 15 e0 50 40 00    	mov    0x4050e0,%edx
  401200:	8b 42 10             	mov    0x10(%edx),%eax
  401203:	89 04 24             	mov    %eax,(%esp)
  401206:	e8 05 07 00 00       	call   401910 <__setmode>
  40120b:	8b 15 e0 50 40 00    	mov    0x4050e0,%edx
  401211:	e9 55 ff ff ff       	jmp    40116b <___mingw_CRTStartup+0x6b>
  401216:	8d 76 00             	lea    0x0(%esi),%esi
  401219:	8d bc 27 00 00 00 00 	lea    0x0(%edi),%edi

00401220 <_mainCRTStartup>:
  401220:	55                   	push   %ebp
  401221:	89 e5                	mov    %esp,%ebp
  401223:	83 ec 08             	sub    $0x8,%esp
  401226:	c7 04 24 01 00 00 00 	movl   $0x1,(%esp)
  40122d:	ff 15 d4 50 40 00    	call   *0x4050d4
  401233:	e8 c8 fe ff ff       	call   401100 <___mingw_CRTStartup>
  401238:	90                   	nop    
  401239:	8d b4 26 00 00 00 00 	lea    0x0(%esi),%esi

00401240 <_WinMainCRTStartup>:
  401240:	55                   	push   %ebp
  401241:	89 e5                	mov    %esp,%ebp
  401243:	83 ec 08             	sub    $0x8,%esp
  401246:	c7 04 24 02 00 00 00 	movl   $0x2,(%esp)
  40124d:	ff 15 d4 50 40 00    	call   *0x4050d4
  401253:	e8 a8 fe ff ff       	call   401100 <___mingw_CRTStartup>
  401258:	90                   	nop    
  401259:	8d b4 26 00 00 00 00 	lea    0x0(%esi),%esi

00401260 <_atexit>:
  401260:	55                   	push   %ebp
  401261:	8b 0d f0 50 40 00    	mov    0x4050f0,%ecx
  401267:	89 e5                	mov    %esp,%ebp
  401269:	5d                   	pop    %ebp
  40126a:	ff e1                	jmp    *%ecx
  40126c:	8d 74 26 00          	lea    0x0(%esi),%esi

00401270 <__onexit>:
  401270:	55                   	push   %ebp
  401271:	8b 0d e4 50 40 00    	mov    0x4050e4,%ecx
  401277:	89 e5                	mov    %esp,%ebp
  401279:	5d                   	pop    %ebp
  40127a:	ff e1                	jmp    *%ecx
  40127c:	90                   	nop    
  40127d:	90                   	nop    
  40127e:	90                   	nop    
  40127f:	90                   	nop    

00401280 <___do_sjlj_init>:
  401280:	55                   	push   %ebp
  401281:	89 e5                	mov    %esp,%ebp
  401283:	5d                   	pop    %ebp
  401284:	e9 77 03 00 00       	jmp    401600 <___w32_sharedptr_initialize>
  401289:	90                   	nop    
  40128a:	90                   	nop    
  40128b:	90                   	nop    
  40128c:	90                   	nop    
  40128d:	90                   	nop    
  40128e:	90                   	nop    
  40128f:	90                   	nop    

00401290 <__Z5getxsPc>:
  401290:	55                   	push   %ebp
  401291:	89 e5                	mov    %esp,%ebp
  401293:	83 ec 18             	sub    $0x18,%esp
  401296:	c7 45 f8 01 00 00 00 	movl   $0x1,0xfffffff8(%ebp)
  40129d:	c7 45 f4 00 00 00 00 	movl   $0x0,0xfffffff4(%ebp)
  4012a4:	8b 45 08             	mov    0x8(%ebp),%eax
  4012a7:	89 45 f0             	mov    %eax,0xfffffff0(%ebp)
  4012aa:	e8 61 07 00 00       	call   401a10 <_getchar>
  4012af:	89 45 fc             	mov    %eax,0xfffffffc(%ebp)
  4012b2:	83 7d fc ff          	cmpl   $0xffffffff,0xfffffffc(%ebp)
  4012b6:	0f 84 8a 00 00 00    	je     401346 <__Z5getxsPc+0xb6>
  4012bc:	83 7d fc 0a          	cmpl   $0xa,0xfffffffc(%ebp)
  4012c0:	0f 84 80 00 00 00    	je     401346 <__Z5getxsPc+0xb6>
  4012c6:	8b 45 fc             	mov    0xfffffffc(%ebp),%eax
  4012c9:	89 04 24             	mov    %eax,(%esp)
  4012cc:	e8 7f 06 00 00       	call   401950 <_isxdigit>
  4012d1:	85 c0                	test   %eax,%eax
  4012d3:	74 d5                	je     4012aa <__Z5getxsPc+0x1a>
  4012d5:	83 7d fc 2f          	cmpl   $0x2f,0xfffffffc(%ebp)
  4012d9:	7e 11                	jle    4012ec <__Z5getxsPc+0x5c>
  4012db:	83 7d fc 39          	cmpl   $0x39,0xfffffffc(%ebp)
  4012df:	7f 0b                	jg     4012ec <__Z5getxsPc+0x5c>
  4012e1:	8b 45 fc             	mov    0xfffffffc(%ebp),%eax
  4012e4:	83 e8 30             	sub    $0x30,%eax
  4012e7:	89 45 ec             	mov    %eax,0xffffffec(%ebp)
  4012ea:	eb 20                	jmp    40130c <__Z5getxsPc+0x7c>
  4012ec:	83 7d fc 40          	cmpl   $0x40,0xfffffffc(%ebp)
  4012f0:	7e 11                	jle    401303 <__Z5getxsPc+0x73>
  4012f2:	83 7d fc 46          	cmpl   $0x46,0xfffffffc(%ebp)
  4012f6:	7f 0b                	jg     401303 <__Z5getxsPc+0x73>
  4012f8:	8b 45 fc             	mov    0xfffffffc(%ebp),%eax
  4012fb:	83 e8 37             	sub    $0x37,%eax
  4012fe:	89 45 ec             	mov    %eax,0xffffffec(%ebp)
  401301:	eb 09                	jmp    40130c <__Z5getxsPc+0x7c>
  401303:	8b 45 fc             	mov    0xfffffffc(%ebp),%eax
  401306:	83 e8 57             	sub    $0x57,%eax
  401309:	89 45 ec             	mov    %eax,0xffffffec(%ebp)
  40130c:	83 7d f8 00          	cmpl   $0x0,0xfffffff8(%ebp)
  401310:	74 0f                	je     401321 <__Z5getxsPc+0x91>
  401312:	8b 45 ec             	mov    0xffffffec(%ebp),%eax
  401315:	89 45 f4             	mov    %eax,0xfffffff4(%ebp)
  401318:	c7 45 f8 00 00 00 00 	movl   $0x0,0xfffffff8(%ebp)
  40131f:	eb 89                	jmp    4012aa <__Z5getxsPc+0x1a>
  401321:	8b 45 f0             	mov    0xfffffff0(%ebp),%eax
  401324:	89 c1                	mov    %eax,%ecx
  401326:	8b 45 f4             	mov    0xfffffff4(%ebp),%eax
  401329:	89 c2                	mov    %eax,%edx
  40132b:	c1 e2 04             	shl    $0x4,%edx
  40132e:	8b 45 ec             	mov    0xffffffec(%ebp),%eax
  401331:	00 d0                	add    %dl,%al
  401333:	88 01                	mov    %al,(%ecx)
  401335:	8d 45 f0             	lea    0xfffffff0(%ebp),%eax
  401338:	ff 00                	incl   (%eax)
  40133a:	c7 45 f8 01 00 00 00 	movl   $0x1,0xfffffff8(%ebp)
  401341:	e9 64 ff ff ff       	jmp    4012aa <__Z5getxsPc+0x1a>
  401346:	8b 45 f0             	mov    0xfffffff0(%ebp),%eax
  401349:	c6 00 00             	movb   $0x0,(%eax)
  40134c:	8d 45 f0             	lea    0xfffffff0(%ebp),%eax
  40134f:	ff 00                	incl   (%eax)
  401351:	8b 45 08             	mov    0x8(%ebp),%eax
  401354:	c9                   	leave  
  401355:	c3                   	ret    

00401356 <__Z6getbufv>:
  401356:	55                   	push   %ebp
  401357:	89 e5                	mov    %esp,%ebp
  401359:	83 ec 28             	sub    $0x28,%esp
  40135c:	8d 45 e8             	lea    0xffffffe8(%ebp),%eax
  40135f:	89 04 24             	mov    %eax,(%esp)
  401362:	e8 29 ff ff ff       	call   401290 <__Z5getxsPc>
  401367:	b8 01 00 00 00       	mov    $0x1,%eax
  40136c:	c9                   	leave  
  40136d:	c3                   	ret    

0040136e <__Z4testv>:
  40136e:	55                   	push   %ebp
  40136f:	89 e5                	mov    %esp,%ebp
  401371:	83 ec 18             	sub    $0x18,%esp
  401374:	c7 04 24 00 30 40 00 	movl   $0x403000,(%esp)
  40137b:	e8 c0 05 00 00       	call   401940 <_printf>
  401380:	e8 d1 ff ff ff       	call   401356 <__Z6getbufv>
  401385:	89 45 fc             	mov    %eax,0xfffffffc(%ebp)
  401388:	8b 45 fc             	mov    0xfffffffc(%ebp),%eax
  40138b:	89 44 24 04          	mov    %eax,0x4(%esp)
  40138f:	c7 04 24 11 30 40 00 	movl   $0x403011,(%esp)
  401396:	e8 a5 05 00 00       	call   401940 <_printf>
  40139b:	c9                   	leave  
  40139c:	c3                   	ret    
  40139d:	90                   	nop    

0040139e <_main>:
  40139e:	55                   	push   %ebp
  40139f:	89 e5                	mov    %esp,%ebp
  4013a1:	83 ec 78             	sub    $0x78,%esp
  4013a4:	83 e4 f0             	and    $0xfffffff0,%esp
  4013a7:	b8 00 00 00 00       	mov    $0x0,%eax
  4013ac:	83 c0 0f             	add    $0xf,%eax
  4013af:	83 c0 0f             	add    $0xf,%eax
  4013b2:	c1 e8 04             	shr    $0x4,%eax
  4013b5:	c1 e0 04             	shl    $0x4,%eax
  4013b8:	89 45 a4             	mov    %eax,0xffffffa4(%ebp)
  4013bb:	8b 45 a4             	mov    0xffffffa4(%ebp),%eax
  4013be:	e8 7d 04 00 00       	call   401840 <___chkstk>
  4013c3:	e8 18 01 00 00       	call   4014e0 <___main>
  4013c8:	8d 45 b8             	lea    0xffffffb8(%ebp),%eax
  4013cb:	25 ff 0f 00 00       	and    $0xfff,%eax
  4013d0:	89 45 b4             	mov    %eax,0xffffffb4(%ebp)
  4013d3:	8b 45 b4             	mov    0xffffffb4(%ebp),%eax
  4013d6:	89 04 24             	mov    %eax,(%esp)
  4013d9:	e8 52 05 00 00       	call   401930 <_malloc>
  4013de:	89 45 b0             	mov    %eax,0xffffffb0(%ebp)
  4013e1:	8b 45 b0             	mov    0xffffffb0(%ebp),%eax
  4013e4:	c7 00 00 00 00 00    	movl   $0x0,(%eax)
  4013ea:	e8 7f ff ff ff       	call   40136e <__Z4testv>
  4013ef:	b8 00 00 00 00       	mov    $0x0,%eax
  4013f4:	c9                   	leave  
  4013f5:	c3                   	ret    
  4013f6:	90                   	nop    
  4013f7:	90                   	nop    
  4013f8:	90                   	nop    
  4013f9:	90                   	nop    
  4013fa:	90                   	nop    
  4013fb:	90                   	nop    
  4013fc:	90                   	nop    
  4013fd:	90                   	nop    
  4013fe:	90                   	nop    
  4013ff:	90                   	nop    

00401400 <__pei386_runtime_relocator>:
  401400:	55                   	push   %ebp
  401401:	b9 10 31 40 00       	mov    $0x403110,%ecx
  401406:	89 e5                	mov    %esp,%ebp
  401408:	eb 14                	jmp    40141e <__pei386_runtime_relocator+0x1e>
  40140a:	8d b6 00 00 00 00    	lea    0x0(%esi),%esi
  401410:	8b 51 04             	mov    0x4(%ecx),%edx
  401413:	8b 01                	mov    (%ecx),%eax
  401415:	83 c1 08             	add    $0x8,%ecx
  401418:	01 82 00 00 40 00    	add    %eax,0x400000(%edx)
  40141e:	81 f9 10 31 40 00    	cmp    $0x403110,%ecx
  401424:	72 ea                	jb     401410 <__pei386_runtime_relocator+0x10>
  401426:	5d                   	pop    %ebp
  401427:	c3                   	ret    
  401428:	90                   	nop    
  401429:	90                   	nop    
  40142a:	90                   	nop    
  40142b:	90                   	nop    
  40142c:	90                   	nop    
  40142d:	90                   	nop    
  40142e:	90                   	nop    
  40142f:	90                   	nop    

00401430 <__fpreset>:
  401430:	55                   	push   %ebp
  401431:	89 e5                	mov    %esp,%ebp
  401433:	db e3                	fninit 
  401435:	5d                   	pop    %ebp
  401436:	c3                   	ret    
  401437:	90                   	nop    
  401438:	90                   	nop    
  401439:	90                   	nop    
  40143a:	90                   	nop    
  40143b:	90                   	nop    
  40143c:	90                   	nop    
  40143d:	90                   	nop    
  40143e:	90                   	nop    
  40143f:	90                   	nop    

00401440 <___do_global_dtors>:
  401440:	55                   	push   %ebp
  401441:	89 e5                	mov    %esp,%ebp
  401443:	83 ec 08             	sub    $0x8,%esp
  401446:	a1 20 20 40 00       	mov    0x402020,%eax
  40144b:	8b 08                	mov    (%eax),%ecx
  40144d:	85 c9                	test   %ecx,%ecx
  40144f:	74 26                	je     401477 <___do_global_dtors+0x37>
  401451:	eb 0d                	jmp    401460 <___do_global_dtors+0x20>
  401453:	90                   	nop    
  401454:	90                   	nop    
  401455:	90                   	nop    
  401456:	90                   	nop    
  401457:	90                   	nop    
  401458:	90                   	nop    
  401459:	90                   	nop    
  40145a:	90                   	nop    
  40145b:	90                   	nop    
  40145c:	90                   	nop    
  40145d:	90                   	nop    
  40145e:	90                   	nop    
  40145f:	90                   	nop    
  401460:	ff 10                	call   *(%eax)
  401462:	8b 0d 20 20 40 00    	mov    0x402020,%ecx
  401468:	8b 51 04             	mov    0x4(%ecx),%edx
  40146b:	8d 41 04             	lea    0x4(%ecx),%eax
  40146e:	a3 20 20 40 00       	mov    %eax,0x402020
  401473:	85 d2                	test   %edx,%edx
  401475:	75 e9                	jne    401460 <___do_global_dtors+0x20>
  401477:	c9                   	leave  
  401478:	c3                   	ret    
  401479:	8d b4 26 00 00 00 00 	lea    0x0(%esi),%esi

00401480 <___do_global_ctors>:
  401480:	55                   	push   %ebp
  401481:	89 e5                	mov    %esp,%ebp
  401483:	53                   	push   %ebx
  401484:	83 ec 04             	sub    $0x4,%esp
  401487:	a1 4c 1a 40 00       	mov    0x401a4c,%eax
  40148c:	83 f8 ff             	cmp    $0xffffffff,%eax
  40148f:	74 29                	je     4014ba <___do_global_ctors+0x3a>
  401491:	85 c0                	test   %eax,%eax
  401493:	89 c3                	mov    %eax,%ebx
  401495:	74 13                	je     4014aa <___do_global_ctors+0x2a>
  401497:	89 f6                	mov    %esi,%esi
  401499:	8d bc 27 00 00 00 00 	lea    0x0(%edi),%edi
  4014a0:	ff 14 9d 4c 1a 40 00 	call   *0x401a4c(,%ebx,4)
  4014a7:	4b                   	dec    %ebx
  4014a8:	75 f6                	jne    4014a0 <___do_global_ctors+0x20>
  4014aa:	c7 04 24 40 14 40 00 	movl   $0x401440,(%esp)
  4014b1:	e8 aa fd ff ff       	call   401260 <_atexit>
  4014b6:	5b                   	pop    %ebx
  4014b7:	5b                   	pop    %ebx
  4014b8:	5d                   	pop    %ebp
  4014b9:	c3                   	ret    
  4014ba:	8b 0d 50 1a 40 00    	mov    0x401a50,%ecx
  4014c0:	31 c0                	xor    %eax,%eax
  4014c2:	85 c9                	test   %ecx,%ecx
  4014c4:	eb 0a                	jmp    4014d0 <___do_global_ctors+0x50>
  4014c6:	40                   	inc    %eax
  4014c7:	8b 14 85 50 1a 40 00 	mov    0x401a50(,%eax,4),%edx
  4014ce:	85 d2                	test   %edx,%edx
  4014d0:	75 f4                	jne    4014c6 <___do_global_ctors+0x46>
  4014d2:	eb bd                	jmp    401491 <___do_global_ctors+0x11>
  4014d4:	8d b6 00 00 00 00    	lea    0x0(%esi),%esi
  4014da:	8d bf 00 00 00 00    	lea    0x0(%edi),%edi

004014e0 <___main>:
  4014e0:	55                   	push   %ebp
  4014e1:	89 e5                	mov    %esp,%ebp
  4014e3:	53                   	push   %ebx
  4014e4:	83 ec 04             	sub    $0x4,%esp
  4014e7:	a1 20 40 40 00       	mov    0x404020,%eax
  4014ec:	85 c0                	test   %eax,%eax
  4014ee:	75 36                	jne    401526 <___main+0x46>
  4014f0:	a1 4c 1a 40 00       	mov    0x401a4c,%eax
  4014f5:	bb 01 00 00 00       	mov    $0x1,%ebx
  4014fa:	89 1d 20 40 40 00    	mov    %ebx,0x404020
  401500:	83 f8 ff             	cmp    $0xffffffff,%eax
  401503:	74 25                	je     40152a <___main+0x4a>
  401505:	85 c0                	test   %eax,%eax
  401507:	89 c3                	mov    %eax,%ebx
  401509:	74 0f                	je     40151a <___main+0x3a>
  40150b:	90                   	nop    
  40150c:	8d 74 26 00          	lea    0x0(%esi),%esi
  401510:	ff 14 9d 4c 1a 40 00 	call   *0x401a4c(,%ebx,4)
  401517:	4b                   	dec    %ebx
  401518:	75 f6                	jne    401510 <___main+0x30>
  40151a:	c7 04 24 40 14 40 00 	movl   $0x401440,(%esp)
  401521:	e8 3a fd ff ff       	call   401260 <_atexit>
  401526:	5b                   	pop    %ebx
  401527:	5b                   	pop    %ebx
  401528:	5d                   	pop    %ebp
  401529:	c3                   	ret    
  40152a:	8b 0d 50 1a 40 00    	mov    0x401a50,%ecx
  401530:	31 c0                	xor    %eax,%eax
  401532:	85 c9                	test   %ecx,%ecx
  401534:	eb 0a                	jmp    401540 <___main+0x60>
  401536:	40                   	inc    %eax
  401537:	8b 14 85 50 1a 40 00 	mov    0x401a50(,%eax,4),%edx
  40153e:	85 d2                	test   %edx,%edx
  401540:	75 f4                	jne    401536 <___main+0x56>
  401542:	eb c1                	jmp    401505 <___main+0x25>
  401544:	90                   	nop    
  401545:	90                   	nop    
  401546:	90                   	nop    
  401547:	90                   	nop    
  401548:	90                   	nop    
  401549:	90                   	nop    
  40154a:	90                   	nop    
  40154b:	90                   	nop    
  40154c:	90                   	nop    
  40154d:	90                   	nop    
  40154e:	90                   	nop    
  40154f:	90                   	nop    

00401550 <___w32_sharedptr_default_unexpected>:
  401550:	55                   	push   %ebp
  401551:	a1 70 40 40 00       	mov    0x404070,%eax
  401556:	89 e5                	mov    %esp,%ebp
  401558:	5d                   	pop    %ebp
  401559:	8b 48 04             	mov    0x4(%eax),%ecx
  40155c:	ff e1                	jmp    *%ecx
  40155e:	89 f6                	mov    %esi,%esi

00401560 <___w32_sharedptr_get>:
  401560:	55                   	push   %ebp
  401561:	ba 42 00 00 00       	mov    $0x42,%edx
  401566:	89 e5                	mov    %esp,%ebp
  401568:	53                   	push   %ebx
  401569:	0f b7 c0             	movzwl %ax,%eax
  40156c:	83 ec 64             	sub    $0x64,%esp
  40156f:	89 54 24 08          	mov    %edx,0x8(%esp)
  401573:	8d 55 a8             	lea    0xffffffa8(%ebp),%edx
  401576:	31 db                	xor    %ebx,%ebx
  401578:	89 54 24 04          	mov    %edx,0x4(%esp)
  40157c:	89 04 24             	mov    %eax,(%esp)
  40157f:	ff 15 b8 50 40 00    	call   *0x4050b8
  401585:	ba 1f 00 00 00       	mov    $0x1f,%edx
  40158a:	b9 01 00 00 00       	mov    $0x1,%ecx
  40158f:	83 ec 0c             	sub    $0xc,%esp
  401592:	85 c0                	test   %eax,%eax
  401594:	75 07                	jne    40159d <___w32_sharedptr_get+0x3d>
  401596:	eb 46                	jmp    4015de <___w32_sharedptr_get+0x7e>
  401598:	01 c9                	add    %ecx,%ecx
  40159a:	4a                   	dec    %edx
  40159b:	78 0e                	js     4015ab <___w32_sharedptr_get+0x4b>
  40159d:	80 7c 2a a8 41       	cmpb   $0x41,0xffffffa8(%edx,%ebp,1)
  4015a2:	75 f4                	jne    401598 <___w32_sharedptr_get+0x38>
  4015a4:	09 cb                	or     %ecx,%ebx
  4015a6:	01 c9                	add    %ecx,%ecx
  4015a8:	4a                   	dec    %edx
  4015a9:	79 f2                	jns    40159d <___w32_sharedptr_get+0x3d>
  4015ab:	83 3b 3c             	cmpl   $0x3c,(%ebx)
  4015ae:	75 07                	jne    4015b7 <___w32_sharedptr_get+0x57>
  4015b0:	89 d8                	mov    %ebx,%eax
  4015b2:	8b 5d fc             	mov    0xfffffffc(%ebp),%ebx
  4015b5:	c9                   	leave  
  4015b6:	c3                   	ret    
  4015b7:	b9 54 30 40 00       	mov    $0x403054,%ecx
  4015bc:	ba ea 00 00 00       	mov    $0xea,%edx
  4015c1:	89 4c 24 0c          	mov    %ecx,0xc(%esp)
  4015c5:	89 54 24 08          	mov    %edx,0x8(%esp)
  4015c9:	c7 04 24 81 30 40 00 	movl   $0x403081,(%esp)
  4015d0:	b8 a0 30 40 00       	mov    $0x4030a0,%eax
  4015d5:	89 44 24 04          	mov    %eax,0x4(%esp)
  4015d9:	e8 92 02 00 00       	call   401870 <___eprintf>
  4015de:	b8 cc 30 40 00       	mov    $0x4030cc,%eax
  4015e3:	bb e4 00 00 00       	mov    $0xe4,%ebx
  4015e8:	89 44 24 0c          	mov    %eax,0xc(%esp)
  4015ec:	89 5c 24 08          	mov    %ebx,0x8(%esp)
  4015f0:	eb d7                	jmp    4015c9 <___w32_sharedptr_get+0x69>
  4015f2:	8d b4 26 00 00 00 00 	lea    0x0(%esi),%esi
  4015f9:	8d bc 27 00 00 00 00 	lea    0x0(%edi),%edi

00401600 <___w32_sharedptr_initialize>:
  401600:	55                   	push   %ebp
  401601:	89 e5                	mov    %esp,%ebp
  401603:	57                   	push   %edi
  401604:	56                   	push   %esi
  401605:	53                   	push   %ebx
  401606:	81 ec cc 00 00 00    	sub    $0xcc,%esp
  40160c:	8b 0d 70 40 40 00    	mov    0x404070,%ecx
  401612:	85 c9                	test   %ecx,%ecx
  401614:	74 08                	je     40161e <___w32_sharedptr_initialize+0x1e>
  401616:	8d 65 f4             	lea    0xfffffff4(%ebp),%esp
  401619:	5b                   	pop    %ebx
  40161a:	5e                   	pop    %esi
  40161b:	5f                   	pop    %edi
  40161c:	5d                   	pop    %ebp
  40161d:	c3                   	ret    
  40161e:	c7 45 98 41 41 41 41 	movl   $0x41414141,0xffffff98(%ebp)
  401625:	a1 30 30 40 00       	mov    0x403030,%eax
  40162a:	8d 75 98             	lea    0xffffff98(%ebp),%esi
  40162d:	c7 45 9c 41 41 41 41 	movl   $0x41414141,0xffffff9c(%ebp)
  401634:	c7 45 a0 41 41 41 41 	movl   $0x41414141,0xffffffa0(%ebp)
  40163b:	89 45 b8             	mov    %eax,0xffffffb8(%ebp)
  40163e:	a1 34 30 40 00       	mov    0x403034,%eax
  401643:	c7 45 a4 41 41 41 41 	movl   $0x41414141,0xffffffa4(%ebp)
  40164a:	c7 45 a8 41 41 41 41 	movl   $0x41414141,0xffffffa8(%ebp)
  401651:	89 45 bc             	mov    %eax,0xffffffbc(%ebp)
  401654:	a1 38 30 40 00       	mov    0x403038,%eax
  401659:	c7 45 ac 41 41 41 41 	movl   $0x41414141,0xffffffac(%ebp)
  401660:	c7 45 b0 41 41 41 41 	movl   $0x41414141,0xffffffb0(%ebp)
  401667:	89 45 c0             	mov    %eax,0xffffffc0(%ebp)
  40166a:	a1 3c 30 40 00       	mov    0x40303c,%eax
  40166f:	c7 45 b4 41 41 41 41 	movl   $0x41414141,0xffffffb4(%ebp)
  401676:	89 45 c4             	mov    %eax,0xffffffc4(%ebp)
  401679:	a1 40 30 40 00       	mov    0x403040,%eax
  40167e:	89 45 c8             	mov    %eax,0xffffffc8(%ebp)
  401681:	a1 44 30 40 00       	mov    0x403044,%eax
  401686:	89 45 cc             	mov    %eax,0xffffffcc(%ebp)
  401689:	a1 48 30 40 00       	mov    0x403048,%eax
  40168e:	89 45 d0             	mov    %eax,0xffffffd0(%ebp)
  401691:	a1 4c 30 40 00       	mov    0x40304c,%eax
  401696:	89 45 d4             	mov    %eax,0xffffffd4(%ebp)
  401699:	0f b7 05 50 30 40 00 	movzwl 0x403050,%eax
  4016a0:	66 89 45 d8          	mov    %ax,0xffffffd8(%ebp)
  4016a4:	89 34 24             	mov    %esi,(%esp)
  4016a7:	ff 15 b4 50 40 00    	call   *0x4050b4
  4016ad:	0f b7 c0             	movzwl %ax,%eax
  4016b0:	83 ec 04             	sub    $0x4,%esp
  4016b3:	85 c0                	test   %eax,%eax
  4016b5:	89 85 44 ff ff ff    	mov    %eax,0xffffff44(%ebp)
  4016bb:	0f 85 3b 01 00 00    	jne    4017fc <___w32_sharedptr_initialize+0x1fc>
  4016c1:	c7 04 24 3c 00 00 00 	movl   $0x3c,(%esp)
  4016c8:	e8 63 02 00 00       	call   401930 <_malloc>
  4016cd:	85 c0                	test   %eax,%eax
  4016cf:	89 c3                	mov    %eax,%ebx
  4016d1:	0f 84 59 01 00 00    	je     401830 <___w32_sharedptr_initialize+0x230>
  4016d7:	fc                   	cld    
  4016d8:	89 c7                	mov    %eax,%edi
  4016da:	8b 85 44 ff ff ff    	mov    0xffffff44(%ebp),%eax
  4016e0:	b9 0f 00 00 00       	mov    $0xf,%ecx
  4016e5:	f3 ab                	repz stos %eax,%es:(%edi)
  4016e7:	c7 43 04 80 19 40 00 	movl   $0x401980,0x4(%ebx)
  4016ee:	b9 01 00 00 00       	mov    $0x1,%ecx
  4016f3:	c7 43 08 50 15 40 00 	movl   $0x401550,0x8(%ebx)
  4016fa:	a1 40 40 40 00       	mov    0x404040,%eax
  4016ff:	c7 03 3c 00 00 00    	movl   $0x3c,(%ebx)
  401705:	8b 15 44 40 40 00    	mov    0x404044,%edx
  40170b:	c7 43 28 00 00 00 00 	movl   $0x0,0x28(%ebx)
  401712:	89 43 14             	mov    %eax,0x14(%ebx)
  401715:	a1 30 20 40 00       	mov    0x402030,%eax
  40171a:	89 53 18             	mov    %edx,0x18(%ebx)
  40171d:	8b 15 34 20 40 00    	mov    0x402034,%edx
  401723:	89 43 1c             	mov    %eax,0x1c(%ebx)
  401726:	a1 50 40 40 00       	mov    0x404050,%eax
  40172b:	89 53 20             	mov    %edx,0x20(%ebx)
  40172e:	c7 43 30 ff ff ff ff 	movl   $0xffffffff,0x30(%ebx)
  401735:	89 43 2c             	mov    %eax,0x2c(%ebx)
  401738:	8b 15 3c 20 40 00    	mov    0x40203c,%edx
  40173e:	a1 38 20 40 00       	mov    0x402038,%eax
  401743:	89 53 38             	mov    %edx,0x38(%ebx)
  401746:	ba 1f 00 00 00       	mov    $0x1f,%edx
  40174b:	89 43 34             	mov    %eax,0x34(%ebx)
  40174e:	89 f6                	mov    %esi,%esi
  401750:	89 d8                	mov    %ebx,%eax
  401752:	21 c8                	and    %ecx,%eax
  401754:	83 f8 01             	cmp    $0x1,%eax
  401757:	19 c0                	sbb    %eax,%eax
  401759:	24 20                	and    $0x20,%al
  40175b:	01 c9                	add    %ecx,%ecx
  40175d:	04 41                	add    $0x41,%al
  40175f:	88 84 2a 48 ff ff ff 	mov    %al,0xffffff48(%edx,%ebp,1)
  401766:	4a                   	dec    %edx
  401767:	79 e7                	jns    401750 <___w32_sharedptr_initialize+0x150>
  401769:	a1 30 30 40 00       	mov    0x403030,%eax
  40176e:	89 85 68 ff ff ff    	mov    %eax,0xffffff68(%ebp)
  401774:	a1 34 30 40 00       	mov    0x403034,%eax
  401779:	89 85 6c ff ff ff    	mov    %eax,0xffffff6c(%ebp)
  40177f:	a1 38 30 40 00       	mov    0x403038,%eax
  401784:	89 85 70 ff ff ff    	mov    %eax,0xffffff70(%ebp)
  40178a:	a1 3c 30 40 00       	mov    0x40303c,%eax
  40178f:	89 85 74 ff ff ff    	mov    %eax,0xffffff74(%ebp)
  401795:	a1 40 30 40 00       	mov    0x403040,%eax
  40179a:	89 85 78 ff ff ff    	mov    %eax,0xffffff78(%ebp)
  4017a0:	a1 44 30 40 00       	mov    0x403044,%eax
  4017a5:	89 85 7c ff ff ff    	mov    %eax,0xffffff7c(%ebp)
  4017ab:	a1 48 30 40 00       	mov    0x403048,%eax
  4017b0:	89 45 80             	mov    %eax,0xffffff80(%ebp)
  4017b3:	a1 4c 30 40 00       	mov    0x40304c,%eax
  4017b8:	89 45 84             	mov    %eax,0xffffff84(%ebp)
  4017bb:	0f b7 05 50 30 40 00 	movzwl 0x403050,%eax
  4017c2:	66 89 45 88          	mov    %ax,0xffffff88(%ebp)
  4017c6:	8d 85 48 ff ff ff    	lea    0xffffff48(%ebp),%eax
  4017cc:	89 04 24             	mov    %eax,(%esp)
  4017cf:	ff 15 ac 50 40 00    	call   *0x4050ac
  4017d5:	0f b7 f8             	movzwl %ax,%edi
  4017d8:	83 ec 04             	sub    $0x4,%esp
  4017db:	85 ff                	test   %edi,%edi
  4017dd:	75 42                	jne    401821 <___w32_sharedptr_initialize+0x221>
  4017df:	31 d2                	xor    %edx,%edx
  4017e1:	85 d2                	test   %edx,%edx
  4017e3:	75 1e                	jne    401803 <___w32_sharedptr_initialize+0x203>
  4017e5:	89 1c 24             	mov    %ebx,(%esp)
  4017e8:	e8 83 01 00 00       	call   401970 <_free>
  4017ed:	89 34 24             	mov    %esi,(%esp)
  4017f0:	ff 15 b4 50 40 00    	call   *0x4050b4
  4017f6:	83 ec 04             	sub    $0x4,%esp
  4017f9:	0f b7 c0             	movzwl %ax,%eax
  4017fc:	e8 5f fd ff ff       	call   401560 <___w32_sharedptr_get>
  401801:	89 c3                	mov    %eax,%ebx
  401803:	89 1d 70 40 40 00    	mov    %ebx,0x404070
  401809:	8d 43 04             	lea    0x4(%ebx),%eax
  40180c:	a3 60 40 40 00       	mov    %eax,0x404060
  401811:	8d 43 08             	lea    0x8(%ebx),%eax
  401814:	a3 80 40 40 00       	mov    %eax,0x404080
  401819:	8d 65 f4             	lea    0xfffffff4(%ebp),%esp
  40181c:	5b                   	pop    %ebx
  40181d:	5e                   	pop    %esi
  40181e:	5f                   	pop    %edi
  40181f:	5d                   	pop    %ebp
  401820:	c3                   	ret    
  401821:	89 f8                	mov    %edi,%eax
  401823:	e8 38 fd ff ff       	call   401560 <___w32_sharedptr_get>
  401828:	39 d8                	cmp    %ebx,%eax
  40182a:	89 fa                	mov    %edi,%edx
  40182c:	75 b1                	jne    4017df <___w32_sharedptr_initialize+0x1df>
  40182e:	eb b1                	jmp    4017e1 <___w32_sharedptr_initialize+0x1e1>
  401830:	e8 4b 01 00 00       	call   401980 <_abort>
  401835:	90                   	nop    
  401836:	90                   	nop    
  401837:	90                   	nop    
  401838:	90                   	nop    
  401839:	90                   	nop    
  40183a:	90                   	nop    
  40183b:	90                   	nop    
  40183c:	90                   	nop    
  40183d:	90                   	nop    
  40183e:	90                   	nop    
  40183f:	90                   	nop    

00401840 <___chkstk>:
  401840:	51                   	push   %ecx
  401841:	89 e1                	mov    %esp,%ecx
  401843:	83 c1 08             	add    $0x8,%ecx

00401846 <probe>:
  401846:	3d 00 10 00 00       	cmp    $0x1000,%eax
  40184b:	72 10                	jb     40185d <done>
  40184d:	81 e9 00 10 00 00    	sub    $0x1000,%ecx
  401853:	83 09 00             	orl    $0x0,(%ecx)
  401856:	2d 00 10 00 00       	sub    $0x1000,%eax
  40185b:	eb e9                	jmp    401846 <probe>

0040185d <done>:
  40185d:	29 c1                	sub    %eax,%ecx
  40185f:	83 09 00             	orl    $0x0,(%ecx)
  401862:	89 e0                	mov    %esp,%eax
  401864:	89 cc                	mov    %ecx,%esp
  401866:	8b 08                	mov    (%eax),%ecx
  401868:	8b 40 04             	mov    0x4(%eax),%eax
  40186b:	ff e0                	jmp    *%eax
  40186d:	90                   	nop    
  40186e:	90                   	nop    
  40186f:	90                   	nop    

00401870 <___eprintf>:
  401870:	55                   	push   %ebp
  401871:	89 e5                	mov    %esp,%ebp
  401873:	83 ec 18             	sub    $0x18,%esp
  401876:	8b 45 14             	mov    0x14(%ebp),%eax
  401879:	89 44 24 10          	mov    %eax,0x10(%esp)
  40187d:	8b 45 10             	mov    0x10(%ebp),%eax
  401880:	89 44 24 0c          	mov    %eax,0xc(%esp)
  401884:	8b 45 0c             	mov    0xc(%ebp),%eax
  401887:	89 44 24 08          	mov    %eax,0x8(%esp)
  40188b:	8b 45 08             	mov    0x8(%ebp),%eax
  40188e:	89 44 24 04          	mov    %eax,0x4(%esp)
  401892:	a1 e0 50 40 00       	mov    0x4050e0,%eax
  401897:	83 c0 40             	add    $0x40,%eax
  40189a:	89 04 24             	mov    %eax,(%esp)
  40189d:	e8 fe 00 00 00       	call   4019a0 <_fprintf>
  4018a2:	a1 e0 50 40 00       	mov    0x4050e0,%eax
  4018a7:	83 c0 40             	add    $0x40,%eax
  4018aa:	89 04 24             	mov    %eax,(%esp)
  4018ad:	e8 de 00 00 00       	call   401990 <_fflush>
  4018b2:	e8 c9 00 00 00       	call   401980 <_abort>
  4018b7:	90                   	nop    
  4018b8:	90                   	nop    
  4018b9:	90                   	nop    
  4018ba:	90                   	nop    
  4018bb:	90                   	nop    
  4018bc:	90                   	nop    
  4018bd:	90                   	nop    
  4018be:	90                   	nop    
  4018bf:	90                   	nop    

004018c0 <___set_app_type>:
  4018c0:	ff 25 d4 50 40 00    	jmp    *0x4050d4
  4018c6:	90                   	nop    
  4018c7:	90                   	nop    
	...

004018d0 <__cexit>:
  4018d0:	ff 25 d8 50 40 00    	jmp    *0x4050d8
  4018d6:	90                   	nop    
  4018d7:	90                   	nop    
	...

004018e0 <___p__environ>:
  4018e0:	ff 25 cc 50 40 00    	jmp    *0x4050cc
  4018e6:	90                   	nop    
  4018e7:	90                   	nop    
	...

004018f0 <_signal>:
  4018f0:	ff 25 0c 51 40 00    	jmp    *0x40510c
  4018f6:	90                   	nop    
  4018f7:	90                   	nop    
	...

00401900 <___p__fmode>:
  401900:	ff 25 d0 50 40 00    	jmp    *0x4050d0
  401906:	90                   	nop    
  401907:	90                   	nop    
	...

00401910 <__setmode>:
  401910:	ff 25 e8 50 40 00    	jmp    *0x4050e8
  401916:	90                   	nop    
  401917:	90                   	nop    
	...

00401920 <___getmainargs>:
  401920:	ff 25 c8 50 40 00    	jmp    *0x4050c8
  401926:	90                   	nop    
  401927:	90                   	nop    
	...

00401930 <_malloc>:
  401930:	ff 25 04 51 40 00    	jmp    *0x405104
  401936:	90                   	nop    
  401937:	90                   	nop    
	...

00401940 <_printf>:
  401940:	ff 25 08 51 40 00    	jmp    *0x405108
  401946:	90                   	nop    
  401947:	90                   	nop    
	...

00401950 <_isxdigit>:
  401950:	ff 25 00 51 40 00    	jmp    *0x405100
  401956:	90                   	nop    
  401957:	90                   	nop    
	...

00401960 <__filbuf>:
  401960:	ff 25 dc 50 40 00    	jmp    *0x4050dc
  401966:	90                   	nop    
  401967:	90                   	nop    
	...

00401970 <_free>:
  401970:	ff 25 fc 50 40 00    	jmp    *0x4050fc
  401976:	90                   	nop    
  401977:	90                   	nop    
	...

00401980 <_abort>:
  401980:	ff 25 ec 50 40 00    	jmp    *0x4050ec
  401986:	90                   	nop    
  401987:	90                   	nop    
	...

00401990 <_fflush>:
  401990:	ff 25 f4 50 40 00    	jmp    *0x4050f4
  401996:	90                   	nop    
  401997:	90                   	nop    
	...

004019a0 <_fprintf>:
  4019a0:	ff 25 f8 50 40 00    	jmp    *0x4050f8
  4019a6:	90                   	nop    
  4019a7:	90                   	nop    
	...

004019b0 <_SetUnhandledExceptionFilter@4>:
  4019b0:	ff 25 bc 50 40 00    	jmp    *0x4050bc
  4019b6:	90                   	nop    
  4019b7:	90                   	nop    
	...

004019c0 <_ExitProcess@4>:
  4019c0:	ff 25 b0 50 40 00    	jmp    *0x4050b0
  4019c6:	90                   	nop    
  4019c7:	90                   	nop    
	...

004019d0 <_GetAtomNameA@12>:
  4019d0:	ff 25 b8 50 40 00    	jmp    *0x4050b8
  4019d6:	90                   	nop    
  4019d7:	90                   	nop    
	...

004019e0 <_FindAtomA@4>:
  4019e0:	ff 25 b4 50 40 00    	jmp    *0x4050b4
  4019e6:	90                   	nop    
  4019e7:	90                   	nop    
	...

004019f0 <_AddAtomA@4>:
  4019f0:	ff 25 ac 50 40 00    	jmp    *0x4050ac
  4019f6:	90                   	nop    
  4019f7:	90                   	nop    
	...

00401a00 <___sjlj_init_ctor>:
  401a00:	55                   	push   %ebp
  401a01:	89 e5                	mov    %esp,%ebp
  401a03:	5d                   	pop    %ebp
  401a04:	e9 77 f8 ff ff       	jmp    401280 <___do_sjlj_init>
  401a09:	90                   	nop    
  401a0a:	90                   	nop    
  401a0b:	90                   	nop    
  401a0c:	90                   	nop    
  401a0d:	90                   	nop    
  401a0e:	90                   	nop    
  401a0f:	90                   	nop    

00401a10 <_getchar>:
  401a10:	55                   	push   %ebp
  401a11:	89 e5                	mov    %esp,%ebp
  401a13:	83 ec 08             	sub    $0x8,%esp
  401a16:	a1 e0 50 40 00       	mov    0x4050e0,%eax
  401a1b:	ff 48 04             	decl   0x4(%eax)
  401a1e:	83 78 04 00          	cmpl   $0x0,0x4(%eax)
  401a22:	78 11                	js     401a35 <_getchar+0x25>
  401a24:	a1 e0 50 40 00       	mov    0x4050e0,%eax
  401a29:	8b 10                	mov    (%eax),%edx
  401a2b:	0f b6 12             	movzbl (%edx),%edx
  401a2e:	89 55 fc             	mov    %edx,0xfffffffc(%ebp)
  401a31:	ff 00                	incl   (%eax)
  401a33:	eb 10                	jmp    401a45 <_getchar+0x35>
  401a35:	a1 e0 50 40 00       	mov    0x4050e0,%eax
  401a3a:	89 04 24             	mov    %eax,(%esp)
  401a3d:	e8 1e ff ff ff       	call   401960 <__filbuf>
  401a42:	89 45 fc             	mov    %eax,0xfffffffc(%ebp)
  401a45:	8b 45 fc             	mov    0xfffffffc(%ebp),%eax
  401a48:	c9                   	leave  
  401a49:	c3                   	ret    
  401a4a:	90                   	nop    
  401a4b:	90                   	nop    

00401a4c <__CTOR_LIST__>:
  401a4c:	ff                   	(bad)  
  401a4d:	ff                   	(bad)  
  401a4e:	ff                   	(bad)  
  401a4f:	ff 00                	incl   (%eax)

00401a50 <.ctors>:
  401a50:	00 1a                	add    %bl,(%edx)
  401a52:	40                   	inc    %eax
  401a53:	00 00                	add    %al,(%eax)
  401a55:	00 00                	add    %al,(%eax)
	...

00401a58 <__DTOR_LIST__>:
  401a58:	ff                   	(bad)  
  401a59:	ff                   	(bad)  
  401a5a:	ff                   	(bad)  
  401a5b:	ff 00                	incl   (%eax)
  401a5d:	00 00                	add    %al,(%eax)
	...
