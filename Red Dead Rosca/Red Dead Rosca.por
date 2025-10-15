programa
{
	inclua biblioteca Graficos --> g
	inclua biblioteca Teclado --> t
	inclua biblioteca Util --> u

	inteiro cenario=g.carregar_imagem("C:/Users/giova/Desktop/Projetos/.vscode/Assets Jogos/senaryo t.png"), cenario_x=0, cenario_y=0
	inteiro n1x = u.sorteia(0,100), n1y = u.sorteia(0,100), aux=0
	inteiro n2x = u.sorteia(200,300), n2y = u.sorteia(0,100)
	inteiro n3x = u.sorteia(300,400), n3y = u.sorteia(50,100)
	inteiro n4x = u.sorteia(400,500), n4y = u.sorteia(0,50)
	inteiro n5x = u.sorteia(-300,-100), n5y = u.sorteia(0,50)
	inteiro n6x = u.sorteia(-400,-300), n6y = u.sorteia(50,100)
	inteiro tamx=u.sorteia(100, 300), tamy=u.sorteia(50, 100)
	inteiro tamx2=u.sorteia(50, 100), tamy2=u.sorteia(40, 70)
	inteiro tamx3=u.sorteia(300, 500), tamy3=u.sorteia(50, 100)
	inteiro tamx4=u.sorteia(150, 700), tamy4=u.sorteia(50, 100)
	inteiro tamx5=u.sorteia(150, 200), tamy5=u.sorteia(50, 150)
	inteiro tamx6=u.sorteia(100, 300), tamy6=u.sorteia(30, 80)
	inteiro bot=0
	inteiro p1wins=g.carregar_imagem("C:/Users/giova//Desktop/Projetos/.vscode/Assets Jogos//viado 1 wins.png"), p1wins_x=230, p1wins_y=100
	inteiro p2wins=g.carregar_imagem("C:/Users/giova//Desktop/Projetos/.vscode/Assets Jogos//viado 2 wins.png"), p2wins_x=200, p2wins_y=100
	inteiro neg=g.carregar_imagem("C:/Users/giova//Desktop/Projetos/.vscode/Assets Jogos//negao da pica cort.png"), neg_x=350, neg_y=0
	inteiro dnv=0
	//PLAYER 1
	inteiro cb1=g.carregar_imagem("C:/Users/giova//Desktop/Projetos/.vscode/Assets Jogos//cb1 completo.png"), cb_x = 100, cb_y = 560               
	inteiro cb1i=g.carregar_imagem("C:/Users/giova//Desktop/Projetos/.vscode/Assets Jogos//cb1inv.png")
	inteiro jmp=0, pow=0, mun=6, abx=0, dead1=0, fall=0                  
	inteiro bala_x = cb_x+53, bala_y = cb_y+48
	inteiro hb1x=cb_x+10, hb1y=cb_y+10
	logico r1=falso, tomo=falso
	inteiro r1c=500, vida=100, passos=0
	inteiro contsang=u.sorteia(5, 50), sangx=cb_x-30, sangy=cb_y+40, tamsangx=u.sorteia(10, 50), tamsangy=u.sorteia(10, 30), qntsang = 0
	logico sang1 = falso, sang2 = falso, sang3 = falso, sang4 = falso, sang5 = falso
	// Sangue 1
	inteiro sangx1 = 0, sangy1 = 0, tamsangx1 = 0, tamsangy1 = 0, contsang1 = 0
	// Sangue 2
	inteiro sangx2 = 0, sangy2 = 0, tamsangx2 = 0, tamsangy2 = 0, contsang2 = 0
	// Sangue 3
	inteiro sangx3 = 0, sangy3 = 0, tamsangx3 = 0, tamsangy3 = 0, contsang3 = 0
	// Sangue 4
	inteiro sangx4 = 0, sangy4 = 0, tamsangx4 = 0, tamsangy4 = 0, contsang4 = 0
	// Sangue 5
	inteiro sangx5 = 0, sangy5 = 0, tamsangx5 = 0, tamsangy5 = 0, contsang5 = 0
	//PLAYER 2
	inteiro cb2=g.carregar_imagem("C:/Users/giova//Desktop/Projetos/.vscode/Assets Jogos//cb2 completo.png"), cb2_x = 1100, cb2_y = 563               
	inteiro cb2i=g.carregar_imagem("C:/Users/giova//Desktop/Projetos/.vscode/Assets Jogos//cb2inv.png")
	inteiro jmp2=0, pow2=0, mun2=6, abx2=0, dead2=0, fall2=0   
	inteiro bala2_x = cb2_x-10, bala2_y = cb2_y+40              
	inteiro hb2x=cb2_x+40, hb2y=cb2_y+10
	logico r2=falso, tomo2=falso
	inteiro r2c=500, vida2=100, passos2=0//, contsang2=u.sorteia(20, 100)
	logico sang21 = falso, sang22 = falso, sang23 = falso, sang24 = falso, sang25 = falso
	// Sangue 1
	inteiro sang2x1 = 0, sang2y1 = 0, tamsang2x1 = 0, tamsang2y1 = 0, cont2sang1 = 0, qntsang2=0
	// Sangue 2
	inteiro sang2x2 = 0, sang2y2 = 0, tamsang2x2 = 0, tamsang2y2 = 0, cont2sang2 = 0
	// Sangue 3
	inteiro sang2x3 = 0, sang2y3 = 0, tamsang2x3 = 0, tamsang2y3 = 0, cont2sang3 = 0
	// Sangue 4
	inteiro sang2x4 = 0, sang2y4 = 0, tamsang2x4 = 0, tamsang2y4 = 0, cont2sang4 = 0
	// Sangue 5
	inteiro sang2x5 = 0, sang2y5 = 0, tamsang2x5 = 0, tamsang2y5 = 0, cont2sang5 = 0
	//MENU
	inteiro tamtelax=1200, tamtelay=700
	logico menu=verdadeiro
	inteiro cdpause=0
	inteiro opt=1
	logico creds
	logico modo
	logico quit = falso
	logico bangbang=falso
	logico oneshot=falso
	logico solo = falso
	inteiro credits=g.carregar_imagem("C:/Users/giova//Desktop/Projetos/.vscode/Assets Jogos/red dead rosca credits.png")
	inteiro menui=g.carregar_imagem("C:/Users/giova//Desktop/Projetos/.vscode/Assets Jogos/MenuRosca.png")
	inteiro logo=g.carregar_imagem("C:/Users/giova//Desktop/Projetos/.vscode/Assets Jogos/RDR logo.png")
	inteiro modoi=g.carregar_imagem("C:/Users/giova//Desktop/Projetos/.vscode/Assets Jogos/selesao de modo rosca.png")
	//MODO BANGBANG
	inteiro MAX_BALAS = 10
	inteiro bala1v_x[10], bala1v_y[10], bala1_ativo[10]
	inteiro bala2v_x[10], bala2v_y[10], bala2_ativo[10]
	inteiro direcao_bala1[10], direcao_bala2[10]
	inteiro y_inicial_bala1[10], y_inicial_bala2[10]
	inteiro cooldown1 = 0, cooldown2 = 0
	inteiro reload1 = 0, reload2 = 0
	inteiro VELOCIDADE_BALA = 15
	inteiro DANOO = 25
	logico espaco_pressionado = falso
	logico m_pressionado = falso
	logico inv1=falso, inv2=falso
	inteiro win1=0, win2=0
	// Variáveis de pulo para Player 1
	real vel_y1 = 0.0
	logico pulando1 = falso
	const real GRAVIDADE = 0.9
	const real FORCA_PULO_INICIAL = 15.0
	const real FORCA_PULO_SUSTENTADA = 0.4
	const real CHAO = 560.0
	// Variáveis de pulo para Player 2
	real vel_y2 = 0.0
	logico pulando2 = falso
	// Variáveis de knockback ao ser atingido
	real vel_x_knock1 = 0.0
	real vel_x_knock2 = 0.0
	const real KNOCKBACK_FORCA = 5.0 // Ajustado para valor positivo
	const real DESACELERACAO_KNOCK = 0.2
	// Variáveis de morte
	real vel_x_morte1 = 0.0, vel_y_morte1 = 0.0
	logico morrendo1 = falso
	real vel_x_morte2 = 0.0, vel_y_morte2 = 0.0
	logico morrendo2 = falso
	const real EMPURRAO_CHAO = 5.0 // Ajustado para valor positivo
	const real EMPURRAO_AR_X = 7.0 // Ajustado para valor positivo
	const real EMPURRAO_AR_Y = -8.0
	const real DESACELERACAO_X = 0.2
	// Variáveis de agachamento
	logico agachado1 = falso
	logico agachado2 = falso
	//MODO ONESHOT
	inteiro chose=0	//1=carrega, 2=bloqueia, 3=atira

	funcao controle(){
	    se(menu==verdadeiro){
	        cdpause++
	        se(t.tecla_pressionada(t.TECLA_S) e cdpause>50){
	            opt++
	            cdpause=0
	        }
	        se(opt>4){
	            opt=1
	        }
	        se(t.tecla_pressionada(t.TECLA_W) e cdpause>50){
	            opt--
	            cdpause=0
	        }
	        se(opt<1){
	            opt=4
	        }
	        se(opt==1 e t.tecla_pressionada(t.TECLA_ESPACO) e cdpause>50){
	            modo=verdadeiro
	            menu=falso
	            solo=verdadeiro
	            cdpause=0
	            opt=1
	        }
	        se(opt==2 e t.tecla_pressionada(t.TECLA_ESPACO) e cdpause>50){
	            modo=verdadeiro
	            menu=falso
	            solo=falso
	            cdpause=0
	            opt=1
	        }
	        se(opt==3 e t.tecla_pressionada(t.TECLA_ESPACO)){
	            creds=verdadeiro
	        }
	        se(creds==verdadeiro e t.tecla_pressionada(t.TECLA_ENTER)){
	            creds=falso
	        }
	        se(opt==4 e t.tecla_pressionada(t.TECLA_ESPACO)){
	            quit=verdadeiro
	        }
	    }
	    se(modo==verdadeiro){
	        cdpause++
	        se(t.tecla_pressionada(t.TECLA_ENTER)){
	            modo=falso
	            menu=verdadeiro
	        }
	        se(t.tecla_pressionada(t.TECLA_S) e cdpause>50){
	            opt++
	            cdpause=0
	        }
	        se(opt>2){
	            opt=1
	        }
	        se(t.tecla_pressionada(t.TECLA_W) e cdpause>50){
	            opt--
	            cdpause=0
	        }
	        se(opt<1){
	            opt=2
	            
	        }
	        se(opt==1 e t.tecla_pressionada(t.TECLA_ESPACO) e cdpause>50){
	            menu=falso
	            modo=falso
	            bangbang=verdadeiro
	            oneshot=falso
	            cdpause=0
	        }
	        se(opt==2 e t.tecla_pressionada(t.TECLA_ESPACO) e cdpause>50){
	            menu=falso
	            modo=falso
	            oneshot=verdadeiro
	            bangbang=falso
	            cdpause=0
	        }
	    }
	    se(t.tecla_pressionada(t.TECLA_P) e menu==falso e cdpause>100 e modo==falso){
	        menu=verdadeiro
	        cdpause=0
	    }
	    se(t.tecla_pressionada(t.TECLA_P) e menu==verdadeiro e cdpause>100 e modo==falso){
	        menu=falso
	        cdpause=0
	    }
	    cdpause++
	    se(modo==falso e menu==falso e oneshot==falso){
	        // PLAYER 1
			se(t.tecla_pressionada(t.TECLA_A) e dead1==0 e abx==0){
				passos++
				cb_x = cb_x - 3
				hb1x = hb1x - 3
				
			}
			se(t.tecla_pressionada(t.TECLA_D) e dead1==0 e abx==0){
				passos++
				cb_x = cb_x + 3
				hb1x = hb1x + 3
				
			}
			se(t.tecla_pressionada(t.TECLA_S) e dead1==0){
				agachado1 = verdadeiro
				abx = 1
				se(sang1==falso){
					sangy=cb_y+70
				}
			} senao {
				agachado1 = falso
				abx = 0
				se(sang1==falso){
					sangy=cb_y+40
				}
			}
			//RECARGA
			se(mun < 1 e dead1==0){
				r1 = verdadeiro
			}
			se(r1 == verdadeiro){
				r1c--
			}
			se(r1c <= 0){
				r1 = falso
				mun = 6
				r1c = 500
			}
			//COLISÕES
			se(cb_x>1150){
				cb_x=1150
				hb1x=cb_x+10
				sangx=cb_x-30
			}
			se(cb_x<0){
				cb_x=0
				hb1x=cb_x+10
				sangx=cb_x-30
			}
			se(cb_y+3>=cb2_y e cb_y<=cb2_y+100 e cb_x>cb2_x e cb_x<cb2_x+10){
				cb_x=cb2_x
				hb1x=cb_x+10
				sangx=cb_x-30
			}
			se(cb_y+3>=cb2_y e cb_y<=cb2_y+100 e cb_x+50>cb2_x+50 e cb_x<cb2_x+50){
			    cb_x=cb2_x+50
			    hb1x=cb_x+10
			    sangx=cb_x-30
			}
			// Lógica de pulo para Player 1
			se(t.tecla_pressionada(t.TECLA_W) e nao pulando1 e cb_y >= CHAO e dead1==0){
				pulando1 = verdadeiro
				vel_y1 = -FORCA_PULO_INICIAL
			}
			se(pulando1){
				se(t.tecla_pressionada(t.TECLA_W) e vel_y1 < 0){
					vel_y1 = vel_y1 - FORCA_PULO_SUSTENTADA
				}
				cb_y = cb_y + vel_y1
				vel_y1 = vel_y1 + GRAVIDADE
				se(cb_y >= CHAO){
					cb_y = CHAO
					vel_y1 = 0.0
					pulando1 = falso
				}
			}
			// Ajustar hitbox vertical para agachamento
			se(agachado1){
				hb1y = cb_y + 10 + 60
			} senao {
				hb1y = cb_y + 10
			}
			
			// PLAYER 2
			se(solo==falso){
				se(t.tecla_pressionada(t.TECLA_J) e dead2==0 e abx2==0){
					cb2_x = cb2_x - 3
					hb2x = hb2x - 3
					passos2++
				}
				se(t.tecla_pressionada(t.TECLA_L) e dead2==0 e abx2==0){
					cb2_x = cb2_x + 3
					hb2x = hb2x + 3
					passos2++
				}
				se(t.tecla_pressionada(t.TECLA_K) e dead2==0){
					agachado2 = verdadeiro
					abx2 = 1
				} senao {
					agachado2 = falso
					abx2 = 0
				}
			}
			se(mun2 < 1 e dead2==0){
					r2 = verdadeiro
			}
			se(r2 == verdadeiro){
				r2c--
			}
			se(r2c <= 0){
				r2 = falso
				mun2 = 6
				r2c = 500
			}
			//COLISÕES
			se(cb2_x>1150){
				cb2_x=1150
				hb2x=cb2_x+40
			}
			se(cb2_x<0){
				cb2_x=0
				hb2x=cb2_x+40
			}
			// Colisão frontal de cb2 com cb1
			se(cb2_y+3>=cb_y e cb2_y<=cb_y+100 e cb2_x+50>cb_x e cb2_x+50<cb_x+10){
			    cb2_x=cb_x-50
			    hb2x=cb2_x+40
			}
			// Colisão traseira de cb2 com cb1
			se(cb2_y+3>=cb_y e cb2_y<=cb_y+100 e t.tecla_pressionada(t.TECLA_J) e cb2_x-3<=cb_x+50 e cb2_x+50>cb_x+50){
			    cb2_x = cb_x + 50
			    hb2x = cb2_x + 40
			}
			// Lógica de pulo para Player 2
			se(t.tecla_pressionada(t.TECLA_I) e nao pulando2 e cb2_y >= CHAO){
				pulando2 = verdadeiro
				vel_y2 = -FORCA_PULO_INICIAL
			}
			se(pulando2){
				se(t.tecla_pressionada(t.TECLA_I) e vel_y2 < 0){
					vel_y2 = vel_y2 - FORCA_PULO_SUSTENTADA
				}
				cb2_y = cb2_y + vel_y2
				vel_y2 = vel_y2 + GRAVIDADE
				se(cb2_y >= CHAO){
					cb2_y = CHAO
					vel_y2 = 0.0
					pulando2 = falso
				}
			}
			// Ajustar hitbox vertical para agachamento
			se(agachado2){
				hb2y = cb2_y + 10 + 60
				
			} senao {
				hb2y = cb2_y + 10
			}
	
			// Lógica de entrada para o modo bangbang
			se(bangbang==verdadeiro){
				logico espaco_atual = t.tecla_pressionada(t.TECLA_ESPACO)
				logico m_atual = t.tecla_pressionada(t.TECLA_M)
	
				// Disparo do jogador 1
				se(espaco_atual e nao espaco_pressionado e mun > 0 e cooldown1 == 0 e reload1 == 0){
					para (inteiro i = 0; i < MAX_BALAS; i++){
					    se(bala1_ativo[i] == 0){
					        bala1v_x[i] = cb_x + 53
					        se(abx==1){
					        	bala1v_y[i] = cb_y + 70
					        }
					        senao{
					        	bala1v_y[i] = cb_y + 48
					        }
					        y_inicial_bala1[i] = bala1v_y[i]
					        bala1_ativo[i] = 1
					        mun--
					        cooldown1 = 60
					        se(inv1==falso){
					        	 direcao_bala1[i] = 1
					        }
					        senao{
					        	 direcao_bala1[i] = -1
					        }
					        pare
					    }
					}
				}
				
				// Disparo do jogador 2
				se(m_atual e nao m_pressionado e mun2 > 0 e cooldown2 == 0 e reload2 == 0){
					para (inteiro i = 0; i < MAX_BALAS; i++){
						se(bala2_ativo[i] == 0){
							bala2v_x[i] = cb2_x - 10
							 se(abx2==1){
						        	bala2v_y[i] = cb2_y + 70
							 }
						      senao{
						        	bala2v_y[i] = cb2_y + 48
						      }
						     y_inicial_bala2[i] = bala2v_y[i]
							bala2_ativo[i] = 1
							mun2--
							se(inv2==falso){
								direcao_bala2[i]=-1
							}
							senao{
								direcao_bala2[i]=1
							}
							cooldown2 = 60
							pare
						}
					}
				}
	
				espaco_pressionado = espaco_atual
				m_pressionado = m_atual
			}
		}
	}

	funcao bangbanger(){
		// Atualizar cooldowns
		se(cooldown1 > 0){
			cooldown1--
		}
		se(cooldown2 > 0){
			cooldown2--
		}
	
		// Atualizar recargas
		se(reload1 > 0){
			reload1--
			se(reload1 == 0){
				mun = 6
			}
		}
		se(reload2 > 0){
			reload2--
			se(reload2 == 0){
				mun2 = 6
			}
		}
	
		// Mover balas e verificar colisões com knockback
		para (inteiro i = 0; i < MAX_BALAS; i++){
			se(bala1_ativo[i] == 1){
				se(bala1_ativo[i] == 1){
    					bala1v_x[i] = bala1v_x[i] + (VELOCIDADE_BALA * direcao_bala1[i])
				}
				se(bala1v_x[i] >= hb2x e bala1v_x[i] <= hb2x + 30 e bala1v_y[i] >= hb2y e bala1v_y[i] <= hb2y + 120){
					vida2 = vida2 - DANOO
					qntsang2 = u.sorteia(1,5)
					se(qntsang2 >= 1){
					    sang21 = verdadeiro
					    sang2x2 = cb2_x - 20
					    sang2y2 = cb2_y + 50
					    tamsang2x2 = u.sorteia(11, 50)
					    tamsang2y2 = u.sorteia(5, 10)
					    contsang2 = u.sorteia(15, 50)
					}
					se(qntsang2 >= 2){
					    sang22 = verdadeiro
					    sang2x2 = cb2_x - 30
					    sang2y2 = cb2_y + 40
					    tamsang2x2 = u.sorteia(11, 50)
					    tamsang2y2 = u.sorteia(10, 15)
					    contsang2 = u.sorteia(15, 50)
					}
					se(qntsang2 >= 3){
					    sang23 = verdadeiro
					    sang2x3 = cb2_x - 35
					    sang2y3 = cb2_y + 45
					    tamsang2x3 = u.sorteia(11, 50)
					    tamsang2y3 = u.sorteia(7, 12)
					    contsang3 = u.sorteia(15, 50)
					}
					se(qntsang2 >= 4){
					    sang24 = verdadeiro
					    sangx4 = cb2_x - 25
					    sangy4 = cb2_y + 30
					    tamsang2x4 = u.sorteia(11, 50)
					    tamsang2y4 = u.sorteia(10, 20)
					    contsang4 = u.sorteia(15, 50)
					}
					se(qntsang2 == 5){
					    sang25 = verdadeiro
					    sang2x5 = cb2_x - 40
					    sang2y5 = cb2_y + 20
					    tamsang2x5 = u.sorteia(11, 50)
					    tamsang2y5 = u.sorteia(5, 12)
					    contsang5 = u.sorteia(15, 50)
					}
					se(inv1==falso){
						vel_x_knock2 = -KNOCKBACK_FORCA // Empurra P2 para esquerda
					}
					senao{
						vel_x_knock2 = KNOCKBACK_FORCA
					}
					bala1_ativo[i] = 0
				}
				senao se(bala1v_x[i] > 1200){
					bala1_ativo[i] = 0
				}
			}
			se(bala2_ativo[i] == 1){
				se(bala2_ativo[i] == 1){
    					bala2v_x[i] = bala2v_x[i] + (VELOCIDADE_BALA * direcao_bala2[i])
				}
				se(bala2v_x[i] >= hb1x e bala2v_x[i] <= hb1x + 30 e bala2v_y[i] >= hb1y e bala2v_y[i] <= hb1y + 120){
					vida = vida - DANOO
					qntsang = u.sorteia(1,5)
					se(qntsang >= 1){
					    sang1 = verdadeiro
					    sangx1 = cb_x - 20
					    sangy1 = cb_y + 50
					    tamsangx1 = u.sorteia(11, 50)
					    tamsangy1 = u.sorteia(10, tamsangx1)
					    contsang1 = u.sorteia(15, 50)
					}
					se(qntsang >= 2){
					    sang2 = verdadeiro
					    sangx2 = cb_x - 30
					    sangy2 = cb_y + 40
					    tamsangx2 = u.sorteia(11, 50)
					    tamsangy2 = u.sorteia(10, tamsangx2)
					    contsang2 = u.sorteia(15, 50)
					}
					se(qntsang >= 3){
					    sang3 = verdadeiro
					    sangx3 = cb_x - 35
					    sangy3 = cb_y + 45
					    tamsangx3 = u.sorteia(11, 50)
					    tamsangy3 = u.sorteia(10, tamsangx3)
					    contsang3 = u.sorteia(15, 50)
					}
					se(qntsang >= 4){
					    sang4 = verdadeiro
					    sangx4 = cb_x - 25
					    sangy4 = cb_y + 30
					    tamsangx4 = u.sorteia(11, 50)
					    tamsangy4 = u.sorteia(10, tamsangx4)
					    contsang4 = u.sorteia(15, 50)
					}
					se(qntsang == 5){
					    sang5 = verdadeiro
					    sangx5 = cb_x - 40
					    sangy5 = cb_y + 20
					    tamsangx5 = u.sorteia(11, 50)
					    tamsangy5 = u.sorteia(10, tamsangx5)
					    contsang5 = u.sorteia(15, 50)
					}

					se(inv2==falso){
						vel_x_knock1 = KNOCKBACK_FORCA // Empurra P1 para direita
					}
					senao{
						vel_x_knock1 = -KNOCKBACK_FORCA
					}
					bala2_ativo[i] = 0
				}
				senao se(bala2v_x[i] < 0){
					bala2_ativo[i] = 0
				}
			}
		}
	
		// Verificar mortes e iniciar física
		se(vida <= 0 e dead1 == 0){
			dead1 = 1
			morrendo1 = verdadeiro
			se(cb_y >= CHAO){
				vel_x_morte1 = EMPURRAO_CHAO // Empurra para direita
				vel_y_morte1 = 0.0
			} senao {
				vel_x_morte1 = EMPURRAO_AR_X // Empurra para direita
				vel_y_morte1 = 0.0
			}
		}
		se(vida2 <= 0 e dead2 == 0){
			dead2 = 1
			morrendo2 = verdadeiro
			se(cb2_y >= CHAO){
				vel_x_morte2 = -EMPURRAO_CHAO // Empurra para esquerda
				vel_y_morte2 = 0.0
			} senao {
				vel_x_morte2 = -EMPURRAO_AR_X // Empurra para esquerda
				vel_y_morte2 = 0.0
			}
		}
	
		// Atualizar posição com knockback
		se(vel_x_knock1 != 0){
			cb_x = cb_x - vel_x_knock1
			hb1x = hb1x - vel_x_knock1
			se(vel_x_knock1 < 0){
				vel_x_knock1 = vel_x_knock1 + DESACELERACAO_KNOCK
				se(vel_x_knock1 > 0) vel_x_knock1 = 0
			} senao {
				vel_x_knock1 = vel_x_knock1 - DESACELERACAO_KNOCK
				se(vel_x_knock1 < 0) vel_x_knock1 = 0
			}
		}
		se(vel_x_knock2 != 0){
			cb2_x = cb2_x - vel_x_knock2
			hb2x = hb2x - vel_x_knock2
			se(vel_x_knock2 < 0){
				vel_x_knock2 = vel_x_knock2 + DESACELERACAO_KNOCK
				se(vel_x_knock2 > 0) vel_x_knock2 = 0
			} senao {
				vel_x_knock2 = vel_x_knock2 - DESACELERACAO_KNOCK
				se(vel_x_knock2 < 0) vel_x_knock2 = 0
			}
		}
	
		// Atualizar posição durante a morte
		se(morrendo1){
			cb_x = cb_x - vel_x_morte1
			cb_y = cb_y + vel_y_morte1
			hb1x = hb1x - vel_x_morte1
			vel_y_morte1 = vel_y_morte1 + GRAVIDADE
			se(vel_x_morte1 < 0){
				vel_x_morte1 = vel_x_morte1 + DESACELERACAO_X
				se(vel_x_morte1 > 0) vel_x_morte1 = 0
			} senao {
				vel_x_morte1 = vel_x_morte1 - DESACELERACAO_X
				se(vel_x_morte1 < 0) vel_x_morte1 = 0
			}
			se(cb_y >= CHAO){
				cb_y = CHAO
				vel_y_morte1 = 0.0
				morrendo1 = falso
			}
		}
		se(morrendo2){
			cb2_x = cb2_x - vel_x_morte2
			cb2_y = cb2_y + vel_y_morte2
			hb2x = hb2x - vel_x_morte2
			vel_y_morte2 = vel_y_morte2 + GRAVIDADE
			se(vel_x_morte2 < 0){
				vel_x_morte2 = vel_x_morte2 + DESACELERACAO_X
				se(vel_x_morte2 > 0) vel_x_morte2 = 0
			} senao {
				vel_x_morte2 = vel_x_morte2 - DESACELERACAO_X
				se(vel_x_morte2 < 0) vel_x_morte2 = 0
			}
			se(cb2_y >= CHAO){
				cb2_y = CHAO
				vel_y_morte2 = 0.0
				morrendo2 = falso
			}
		}
		 // Atualizar contadores de queda
	    se(dead1 > 0){
	        fall++
	    }
	    se(dead2 > 0){
	        fall2++
	    }
	    	
		// Desenhar personagens
		se(cb_x>cb2_x+49){
			inv1=verdadeiro
		}
		senao{
			inv1=falso
		}
		se(dead1 == 0){
			// Desenhar sangue
			// Partícula 1
			se(sang1 == verdadeiro){
			    se(inv1 == falso){
			        sangx1 -= 2
			    } senao {
			        sangx1 += 2
			    }
			    sangy1++
			    tamsangx1--
			    tamsangy1--
			    contsang1--
			
			    se(contsang1 > 0){
			        g.definir_cor(g.COR_VERMELHO)
			        g.desenhar_elipse(sangx1, sangy1, tamsangx1, tamsangy1, verdadeiro)
			    } senao {
			        sang1 = falso
			    }
			}
			
			// Partícula 2
			se(sang2 == verdadeiro){
			    se(inv1 == falso){
			        sangx2 -= 2
			    } senao {
			        sangx2 += 2
			    }
			    sangy2++
			    tamsangx2--
			    tamsangy2--
			    contsang2--
			
			    se(contsang2 > 0){
			        g.definir_cor(g.COR_VERMELHO)
			        g.desenhar_elipse(sangx2, sangy2, tamsangx2, tamsangy2, verdadeiro)
			    } senao {
			        sang2 = falso
			    }
			}
			// Partícula 3
			se(sang3 == verdadeiro){
			    se(inv1 == falso){
			        sangx3 -= 2
			    } senao {
			        sangx3 += 2
			    }
			    sangy3++
			    tamsangx3--
			    tamsangy3--
			    contsang3--
			
			    se(contsang3 > 0){
			        g.definir_cor(g.COR_VERMELHO)
			        g.desenhar_elipse(sangx3, sangy3, tamsangx3, tamsangy3, verdadeiro)
			    } senao {
			        sang3 = falso
			    }
			}
			// Partícula 4
			se(sang4 == verdadeiro){
			    se(inv1 == falso){
			        sangx4 -= 2
			    } senao {
			        sangx4 += 2
			    }
			    sangy4++
			    tamsangx4--
			    tamsangy4--
			    contsang4--
			
			    se(contsang4 > 0){
			        g.definir_cor(g.COR_VERMELHO)
			        g.desenhar_elipse(sangx4, sangy4, tamsangx4, tamsangy4, verdadeiro)
			    } senao {
			        sang4 = falso
			    }
			}
			// Partícula 5
			se(sang5 == verdadeiro){
			    se(inv1 == falso){
			        sangx5 -= 2
			    } senao {
			        sangx5 += 2
			    }
			    sangy5++
			    tamsangx5--
			    tamsangy5--
			    contsang5--
			
			    se(contsang5 > 0){
			        g.definir_cor(g.COR_VERMELHO)
			        g.desenhar_elipse(sangx5, sangy5, tamsangx5, tamsangy5, verdadeiro)
			    } senao {
			        sang5 = falso
			    }
			}
			se(abx == 0){
				//g.desenhar_imagem(cb_x, cb_y, cb1)
				se(passos>30){
					passos=0
				}
				se(passos>=0 e passos<15){
					se(pulando1==falso){
						se(inv1 == falso){
			                    g.desenhar_porcao_imagem(cb_x, cb_y, 0, 0, 74, 119, cb1)
			                } 
			                senao{
			                    g.desenhar_porcao_imagem(cb_x, cb_y, 0, 0, 74, 119, cb1i)
			                }
					}
				}
				senao{
					se(pulando1==falso){
						se(inv1==falso){
							g.desenhar_porcao_imagem(cb_x, cb_y, 80, 0, 74, 119, cb1)
						}
						senao{
							g.desenhar_porcao_imagem(cb_x, cb_y, 80, 0, 74, 119, cb1i)
						}
					}
				}
				se(pulando1==verdadeiro){
					se(inv1==falso){
						g.desenhar_porcao_imagem(cb_x, cb_y, 154, 0, 73, 114, cb1)
					}
					senao{
						g.desenhar_porcao_imagem(cb_x, cb_y, 154, 0, 73, 114, cb1i)
					}
				}
				
			} 
			senao {
				se(inv1==falso){
					g.desenhar_porcao_imagem(cb_x, cb_y, 610, 0, 89, 120, cb1)
				}
				senao{
					g.desenhar_porcao_imagem(cb_x, cb_y, 610, 0, 89, 120, cb1i)
				}
			}
		} 
		senao {
			se(fall > 0 e fall < 25){
	            se(inv1==falso){
	            	g.desenhar_porcao_imagem(cb_x, cb_y, 230, 0, 88, 120, cb1)
	            }
	            senao{
	            	g.desenhar_porcao_imagem(cb_x, cb_y, 230, 0, 88, 120, cb1i)
	            }
	        }
	        se(fall > 25 e fall < 50){
	            se(inv1==falso){
	            	g.desenhar_porcao_imagem(cb_x-30, cb_y, 333, 0, 119, 120, cb1)
	            }
	            senao{
	            	g.desenhar_porcao_imagem(cb_x-30, cb_y, 333, 0, 119, 120, cb1i)
	            }
	        }
	        se(fall > 50){
	            se(inv1==falso){
	            	g.desenhar_porcao_imagem(cb_x-40, cb_y, 470, 0, 126, 120, cb1)
	            }
	            senao{
	            	g.desenhar_porcao_imagem(cb_x-40, cb_y, 470, 0, 126, 120, cb1i)
	            }
	        }
		}

		se(cb2_x<cb_x){
			inv2=verdadeiro
		}
		senao{
			inv2=falso
		}
		se(dead2 == 0){
			// Desenhar sangue
			// Partícula 1
			se(sang21 == verdadeiro){
			    se(inv2 == falso){
			        sang2x1 -= 2
			    } senao {
			        sang2x1 += 2
			    }
			    sang2y1++
			    tamsang2x1--
			    tamsang2y1--
			    cont2sang1--
			
			    se(cont2sang1 > 0){
			        g.definir_cor(g.COR_VERMELHO)
			        g.desenhar_elipse(sang2x1, sang2y1, tamsang2x1, tamsang2y1, verdadeiro)
			    } senao {
			        sang2 = falso
			    }
			}
			
			// Partícula 2
			se(sang22 == verdadeiro){
			    se(inv2 == falso){
			        sangx2 -= 2
			    } senao {
			        sang2x2 += 2
			    }
			    sang2y2++
			    tamsang2x2--
			    tamsang2y2--
			    cont2sang2--
			
			    se(cont2sang2 > 0){
			        g.definir_cor(g.COR_VERMELHO)
			        g.desenhar_elipse(sang2x2, sang2y2, tamsang2x2, tamsang2y2, verdadeiro)
			    } senao {
			        sang22 = falso
			    }
			}
			// Partícula 3
			se(sang23 == verdadeiro){
			    se(inv2 == falso){
			        sang2x3 -= 2
			    } senao {
			        sang2x3 += 2
			    }
			    sang2y3++
			    tamsang2x3--
			    tamsang2y3--
			    cont2sang3--
			
			    se(cont2sang3 > 0){
			        g.definir_cor(g.COR_VERMELHO)
			        g.desenhar_elipse(sang2x3, sang2y3, tamsang2x3, tamsang2y3, verdadeiro)
			    } senao {
			        sang23 = falso
			    }
			}
			// Partícula 4
			se(sang24 == verdadeiro){
			    se(inv2 == falso){
			        sang2x4 -= 2
			    } senao {
			        sang2x4 += 2
			    }
			    sang2y4++
			    tamsang2x4--
			    tamsang2y4--
			    cont2sang4--
			
			    se(cont2sang4 > 0){
			        g.definir_cor(g.COR_VERMELHO)
			        g.desenhar_elipse(sang2x4, sang2y4, tamsang2x4, tamsang2y4, verdadeiro)
			    } senao {
			        sang24 = falso
			    }
			}
			// Partícula 5
			se(sang25 == verdadeiro){
			    se(inv2 == falso){
			        sang2x5 -= 2
			    } senao {
			        sang2x5 += 2
			    }
			    sang2y5++
			    tamsang2x5--
			    tamsang2y5--
			    cont2sang5--
			
			    se(cont2sang5 > 0){
			        g.definir_cor(g.COR_VERMELHO)
			        g.desenhar_elipse(sang2x5, sang2y5, tamsang2x5, tamsang2y5, verdadeiro)
			    } senao {
			        sang25 = falso
			    }
			}
			
			// Repetir igual para sang3, sang4 e sang5...

			se(abx2 == 0){
				se(passos2>30){
					passos2=0
				}
				se(passos2>=0 e passos2<15){
					se(pulando2==falso){
						se(inv2==falso){
							g.desenhar_porcao_imagem(cb2_x, cb2_y, 0, 0, 74, 119, cb2)
						}
						senao{
							g.desenhar_porcao_imagem(cb2_x, cb2_y, 0, 0, 74, 119, cb2i)
						}
					}
				}
				senao{
					se(pulando2==falso){
						se(inv2==falso){
							g.desenhar_porcao_imagem(cb2_x, cb2_y, 73, 0, 74, 119, cb2)
						}
						senao{
							g.desenhar_porcao_imagem(cb2_x, cb2_y, 73, 0, 74, 119, cb2i)
						}
					}
				}
				se(pulando2==verdadeiro){
					se(inv2==falso){
						g.desenhar_porcao_imagem(cb2_x, cb2_y, 147, 0, 73, 114, cb2)
					}
					senao{
						g.desenhar_porcao_imagem(cb2_x, cb2_y, 147, 0, 73, 114, cb2i)
					}
				}
			} senao {
				se(inv2==falso){
					g.desenhar_porcao_imagem(cb2_x, cb2_y, 610, 0, 89, 120, cb2)
				}
				senao{
					g.desenhar_porcao_imagem(cb2_x, cb2_y, 610, 0, 89, 120, cb2)
				}
			}
		} 
		senao {
			se(fall2 > 0 e fall2 < 25){
	            se(inv2==falso){
	            	g.desenhar_porcao_imagem(cb2_x, cb2_y, 225, 0, 79, 120, cb2)
	            }
	            senao{
	            	g.desenhar_porcao_imagem(cb2_x, cb2_y, 225, 0, 79, 120, cb2i)
	            }
	        }
	        se(fall2 > 25 e fall2 < 50){
	            se(inv2==falso){
	            	g.desenhar_porcao_imagem(cb2_x+10, cb2_y, 315, 0, 110, 150, cb2)
	            }
	            senao{
	            	g.desenhar_porcao_imagem(cb2_x+10, cb2_y, 315, 0, 110, 150, cb2i)
	            }
	        }
	        se(fall2 > 50){
	            se(inv2==falso){
	            	g.desenhar_porcao_imagem(cb2_x+10, cb2_y+4, 442, 0, 143, 118, cb2)
	            }
	            senao{
	            	g.desenhar_porcao_imagem(cb2_x+10, cb2_y+4, 442, 0, 143, 118, cb2i)
	            }
	        }
		}

	
		// Desenhar balas
		para (inteiro i = 0; i < MAX_BALAS; i++){
			se(bala1_ativo[i] == 1){
				g.definir_cor(g.COR_PRETO)
				g.desenhar_elipse(bala1v_x[i], bala1v_y[i], 20, 3, verdadeiro)
			}
			se(bala2_ativo[i] == 1){
				g.definir_cor(g.COR_PRETO)
				g.desenhar_elipse(bala2v_x[i], bala2v_y[i], 20, 3, verdadeiro)
			}
		}
	
		// Desenhar barras de vida
		g.definir_cor(g.COR_VERDE)
		g.desenhar_retangulo(100, 100, vida * 3, 50, falso, verdadeiro)
		g.definir_cor(g.COR_PRETO)
		g.desenhar_retangulo(100, 100, 300, 50, falso, falso)
		g.definir_cor(g.COR_VERDE)
		g.desenhar_retangulo(800, 100, vida2 * 3, 50, falso, verdadeiro)
		g.definir_cor(g.COR_PRETO)
		g.desenhar_retangulo(800, 100, 300, 50, falso, falso)
	
		// Desenhar munição
		g.definir_cor(g.COR_PRETO)
		g.desenhar_texto(100, 400, "Munição P1: " + mun)
		g.desenhar_texto(1000, 400, "Munição P2: " + mun2)
	
		// Indicador de recarga
		se(r2c>0 e r2c<500){
			g.desenhar_texto(1000, 300, "RECARREGANDO...")
		}
		se(r1c>0 e r1c<500){
			g.desenhar_texto(200, 300, "RECARREGANDO...")
		}
	}
	
	funcao desenhar(){
		g.definir_cor(g.COR_BRANCO)
		g.limpar()
		g.desenhar_imagem(0, 0, cenario)
		se(menu==verdadeiro){
			g.desenhar_retangulo(520, 430, 130, 30, verdadeiro, verdadeiro)
			g.desenhar_retangulo(500, 460, 167, 35, verdadeiro, verdadeiro)
			g.desenhar_retangulo(535, 500, 100, 35, verdadeiro, verdadeiro)
			g.desenhar_retangulo(556, 540, 57, 35, verdadeiro, verdadeiro)
			g.definir_cor(g.COR_VERMELHO)
			se(opt==1){
				g.desenhar_retangulo(520, 430, 130, 30, verdadeiro, verdadeiro)
			}
			se(opt==2){
				g.desenhar_retangulo(500, 460, 167, 35, verdadeiro, verdadeiro)
			}
			se(opt==3){
				g.desenhar_retangulo(535, 500, 100, 35, verdadeiro, verdadeiro)
			}
			se(opt==4){
				g.desenhar_retangulo(556, 540, 57, 35, verdadeiro, verdadeiro)
			}
			
			se(creds==falso){
				g.desenhar_imagem(494, 402, menui)
				g.definir_cor(g.COR_PRETO)
				g.desenhar_elipse(0,0, 20, 3, verdadeiro) // Removido bala_x, bala_y
				g.desenhar_elipse(0,0,20, 3, verdadeiro) // Removido bala2_x, bala2_y
				g.definir_cor(g.COR_BRANCO)
				g.desenhar_elipse(n1x, n1y, tamx, tamy, verdadeiro)
				g.desenhar_elipse(n2x, n2y, tamx2, tamy2, verdadeiro)
				g.desenhar_elipse(n3x, n3y, tamx3, tamy3, verdadeiro)
				g.desenhar_elipse(n4x, n4y, tamx4, tamy4, verdadeiro)
				g.desenhar_elipse(n5x, n5y, tamx5, tamy5, verdadeiro)
				g.desenhar_elipse(n6x, n6y, tamx6, tamy6, verdadeiro)
				g.desenhar_imagem(310, 60, logo)
			}
			se(abx==0 e dead1==0){
				g.desenhar_porcao_imagem(cb_x, cb_y, 0, 0, 74, 119, cb1)
			}
			se(abx2==0 e dead2==0){
				g.desenhar_porcao_imagem(cb2_x, cb2_y, 0, 0, 74, 119, cb2)
			}
			
			se(creds==verdadeiro){
				g.desenhar_imagem(0, 0, credits)
			}
		}
		se(modo==verdadeiro){
			g.definir_cor(g.COR_BRANCO)
			g.desenhar_retangulo(483, 433, 202, 30, verdadeiro, verdadeiro)
			g.desenhar_retangulo(495, 473, 181, 28, verdadeiro, verdadeiro)
			g.definir_cor(g.COR_VERMELHO)
			se(opt==1){
				g.desenhar_retangulo(483, 433, 202, 30, verdadeiro, verdadeiro)
			}
			se(opt==2){
				g.desenhar_retangulo(495, 473, 181, 28, verdadeiro, verdadeiro)
			}
			g.desenhar_imagem(470, 350, modoi)
		}
		se(menu==falso e modo==falso e quit==falso){
			g.desenhar_imagem(cenario_x, cenario_y, cenario)
			g.definir_cor(g.COR_BRANCO)
			g.desenhar_elipse(n1x, n1y, tamx, tamy, verdadeiro)
			g.desenhar_elipse(n2x, n2y, tamx2, tamy2, verdadeiro)
			g.desenhar_elipse(n3x, n3y, tamx3, tamy3, verdadeiro)
			g.desenhar_elipse(n4x, n4y, tamx4, tamy4, verdadeiro)
			g.desenhar_elipse(n5x, n5y, tamx5, tamy5, verdadeiro)
			g.desenhar_elipse(n6x, n6y, tamx6, tamy6, verdadeiro)
			aux++
			se(aux%50==0){
				n1x++
				n2x++
				n3x++
				n4x++
				n5x++
				n6x++
			}
			se(bangbang==verdadeiro){
				bangbanger()
				g.definir_cor(g.COR_VERMELHO)
				g.desenhar_retangulo(hb1x, hb1y, 50, 200, falso, falso)
				g.desenhar_retangulo(hb2x, hb2y, 50, 200, falso, falso)
				g.definir_tamanho_texto(20.0)
				g.desenhar_texto(570, 100, ""+win1)
				g.desenhar_texto(570, 100, "   X "+win2)
				g.definir_cor(g.COR_PRETO)
				g.desenhar_texto(105, 110, "PLAYER 1")
				g.desenhar_texto(995, 110, "PLAYER 2")
			}
			se(dead1==0 e dead2>0){
				g.desenhar_imagem(320, 200, p1wins)
				g.desenhar_texto(500, 400, "'R' Para Reiniciar")
				dnv=1
				se(t.tecla_pressionada(t.TECLA_R)){
					win1++
					vida=100
					vida2=100
					dnv=0
					dead1=0
					dead2=0
					mun=6
					mun2=6
					fall=0
					fall2=0
					bala_x=cb_x+53
					bala2_x=cb2_x-10
					cb_x=100
					cb2_x=1100
					cb_y=560
					cb2_y=560
					hb1x=cb_x+10
					hb1y=cb_y+10
					hb2x=cb2_x+40
					hb2y=cb2_y+10
					para (inteiro i = 0; i < MAX_BALAS; i++){
						bala1_ativo[i] = 0
						bala2_ativo[i] = 0
					}
					cooldown1 = 0
					cooldown2 = 0
					reload1 = 0
					reload2 = 0
					vel_x_knock1 = 0.0
					vel_x_knock2 = 0.0
					vel_x_morte1 = 0.0
					vel_y_morte1 = 0.0
					morrendo1 = falso
					vel_x_morte2 = 0.0
					vel_y_morte2 = 0.0
					morrendo2 = falso
					vel_y1 = 0.0
					vel_y2 = 0.0
					pulando1 = falso
					pulando2 = falso
					sangx=cb_x-30
					sangy=cb_y+40
				}
			}
			se(dead2==0 e dead1>0){
				g.desenhar_imagem(270, 200, p2wins)
				g.desenhar_texto(500, 400, "'R' Para Reiniciar")
				dnv=1
				se(t.tecla_pressionada(t.TECLA_R)){
					win2++
					vida=100
					vida2=100
					dnv=0
					dead1=0
					dead2=0
					mun=6
					mun2=6
					fall=0
					fall2=0
					bala_x=cb_x+53
					bala2_x=cb2_x-10
					cb_x=100
					cb2_x=1100
					cb_y=560
					cb2_y=560
					hb1x=cb_x+10
					hb1y=cb_y+10
					hb2x=cb2_x+40
					hb2y=cb2_y+10
					para (inteiro i = 0; i < MAX_BALAS; i++){
						bala1_ativo[i] = 0
						bala2_ativo[i] = 0
					}
					cooldown1 = 0
					cooldown2 = 0
					reload1 = 0
					reload2 = 0
					vel_x_knock1 = 0.0
					vel_x_knock2 = 0.0
					vel_x_morte1 = 0.0
					vel_y_morte1 = 0.0
					morrendo1 = falso
					vel_x_morte2 = 0.0
					vel_y_morte2 = 0.0
					morrendo2 = falso
					vel_y1 = 0.0
					vel_y2 = 0.0
					pulando1 = falso
					pulando2 = falso
					sangx=cb_x-30
					sangy=cb_y+40
				}
			}
			se(dead2>0 e dead1>0){
				g.desenhar_imagem(400,300, neg)
				g.definir_cor(g.COR_BRANCO)
				g.desenhar_elipse(630, 300, 250, 100, verdadeiro)
				g.desenhar_elipse(600, 360, 60, 10, verdadeiro)
				g.definir_cor(g.COR_PRETO)
				g.desenhar_texto(660, 350, "aperta R pra reiniciar")
				dnv=1
				se(t.tecla_pressionada(t.TECLA_R)){
					vida=100
					vida2=100
					dnv=0
					dead1=0
					dead2=0
					mun=6
					mun2=6
					fall=0
					fall2=0
					bala_x=cb_x+53
					bala2_x=cb2_x-10
					cb_x=100
					cb2_x=1100
					cb_y=560
					cb2_y=560
					hb1x=cb_x+10
					hb1y=cb_y+10
					hb2x=cb2_x+40
					hb2y=cb2_y+10
					
					para (inteiro i = 0; i < MAX_BALAS; i++){
						bala1_ativo[i] = 0
						bala2_ativo[i] = 0
					}
					cooldown1 = 0
					cooldown2 = 0
					reload1 = 0
					reload2 = 0
					vel_x_knock1 = 0.0
					vel_x_knock2 = 0.0
					vel_x_morte1 = 0.0
					vel_y_morte1 = 0.0
					morrendo1 = falso
					vel_x_morte2 = 0.0
					vel_y_morte2 = 0.0
					morrendo2 = falso
					vel_y1 = 0.0
					vel_y2 = 0.0
					pulando1 = falso
					pulando2 = falso
					sangx=cb_x-30
					sangy=cb_y+40
				}
			}
		}
		g.renderizar()
	}
	
	funcao inicio(){
		g.iniciar_modo_grafico(verdadeiro)
		g.definir_dimensoes_janela(1200, 700)
		enquanto(quit==falso){
			controle()
			desenhar()
		}
	}	
}