      FVOIDP FUNCTION HIJJET1_ADDRESS() 

      COMMON/HIJJET1/NPJ(300),KFPJ(300,500),PJPX(300,500),
     &     PJPY(300,500),PJPZ(300,500),PJPE(300,500),
     &     PJPM(300,500),NTJ(300),KFTJ(300,500),
     &     PJTX(300,500),PJTY(300,500),PJTZ(300,500),
     &     PJTE(300,500),PJTM(300,500)
      SAVE  /HIJJET1/
      EXTERNAL HIDATA ! All that is required to force loading of BLOCK DATA
      FVOIDP GETADDR

      HIJJET1_ADDRESS = GETADDR(NPJ)
      
      RETURN
      END
