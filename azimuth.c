#include<math.h>
#include<stdio.h>

double radians(double ang)
{
       ang = ang*M_PI/180.0;
       return ang;
}

double degrees(double ang)
{
       ang = ang*180.0/M_PI;
       return ang;
}


double azimute_puissant(double p1x, double p1y, double p2x, double p2y)
{       
        double e2 = 0.00669438002290,
               a = 6378137,
               seno_1segundo = 0.00000484813681108;

        int sinal_x = 0, sinal_y = 0;
        
        double lat_media, seno_lat_media, cos_lat_media, pow_seno_20, nm, delta_lat, delta_lon, mm, bm, x, y, F, gamma, azimute;

        lat_media = (radians(p1y) + radians(p2y)) / 2.0;
        seno_lat_media = sin(lat_media);
        cos_lat_media = cos(lat_media);
        pow_seno_20 = pow(seno_lat_media, 2);
        nm = a/pow(1.0 - e2 * pow_seno_20, 0.5);
        delta_lat = (p2y - p1y)*3600.0;
        delta_lon = (p2x - p1x)*3600.0;

        mm = (a * (1 - e2)) / pow(1 - (e2 * pow_seno_20), 1.5);

        bm = 1/mm*seno_1segundo;

        x = delta_lon * cos_lat_media * nm * seno_1segundo;
        y = delta_lat*cos(radians(delta_lon/7200.0))*mm*seno_1segundo; 
        
        F = (1.0 / 12.0) * seno_lat_media * pow(cos_lat_media,2) * pow(seno_1segundo,2); 
        gamma = (delta_lon * seno_lat_media * (1.0 / cos(radians(delta_lat / 7200.0))) + (F * delta_lon * delta_lon * delta_lon)); 
        
        if (x < 0) sinal_x = -1;
        else sinal_x = 1;

        if (y < 0) sinal_y = -1;
        else sinal_y = 1;

        azimute = 180.0 * (1.0 - (0.5 * sinal_x) - (0.5 * sinal_x * sinal_y)) + (degrees(atan(x / y))) - (gamma / 7200.0);
        
        return azimute;
        
}       

double dd2gms(double value)
{
       
    int g, m;
    float ms, s;

    g = float(value);
    ms = (value - (double)g) * 60;
    m = float(ms);
    s = (ms - (double)m) * 60;

    printf("%d\'%d\'%f\n", g, m, s);

}
       
       
main()
{
       double p1x, p1y, p2x, p2y;
      
        printf("\nTeste AR8-M-0214 - AWN-M-0214\n");
        p1y = -22.233096388889;
        p1x = -50.375877222222;
        p2y = -22.2330358333333;
        p2x = -50.375877222222;
        dd2gms(azimute_puissant(p1x,p1y,p2x,p2y));
        
        printf("\nTeste Parcela Certificada\n");
        p1y = -22.236881388889;
        p1x = -50.377705555556;
        p2y = -22.236799166667;
        p2x = -50.377680833333;
        dd2gms(azimute_puissant(p1x,p1y,p2x,p2y));
        p1x = p2x; p1y = p2y;
        p2y = -22.236174166667;
        p2x = -50.377072777778;
        dd2gms(azimute_puissant(p1x,p1y,p2x,p2y));
        p1x = p2x; p1y = p2y;
        p2y = -22.235517500000;
        p2x = -50.376958888889;
        dd2gms(azimute_puissant(p1x,p1y,p2x,p2y));
        p1x = p2x; p1y = p2y;
        p2y = -22.249812777778;
        p2x = -50.375903055556;
        dd2gms(azimute_puissant(p1x,p1y,p2x,p2y));
        p1x = p2x; p1y = p2y;
        p2y = -22.233096388889;
        p2x = -50.375877222222;
        dd2gms(azimute_puissant(p1x,p1y,p2x,p2y));
        p1x = p2x; p1y = p2y;
        p2y = -22.233035833333;
        p2x = -50.375877222222;
        dd2gms(azimute_puissant(p1x,p1y,p2x,p2y));
        p1x = p2x; p1y = p2y;
        p2y = -22.231296111111;
        p2x = -50.365868611111;
        dd2gms(azimute_puissant(p1x,p1y,p2x,p2y));
        p1x = p2x; p1y = p2y;
        p2y = -22.230758333333;
        p2x = -50.362625277778;
        dd2gms(azimute_puissant(p1x,p1y,p2x,p2y));
        p1x = p2x; p1y = p2y;
        p2y = -22.230381666667;
        p2x = -50.360280277778;
        dd2gms(azimute_puissant(p1x,p1y,p2x,p2y));
        
        
        printf("\nTeste Azimute  igual a zero\n");
        p1x = 0;
        p1y = 0;
        p2x = 0;
        p2y = 1;
        dd2gms(azimute_puissant( p1x, p1y, p2x, p2y));
        
        printf("\nTeste Azimute  igual a 90\n");
        p1x = 0;
        p1y = 0;
        p2x = 1;
        p2y = 0;
        dd2gms(azimute_puissant( p1x, p1y, p2x, p2y));
        
        printf("\nTeste Azimute  igual a 180\n");
        p1x = 0;
        p1y = 0;
        p2x = 0;
        p2y = -1;
        dd2gms(azimute_puissant( p1x, p1y, p2x, p2y));
        
        printf("\nTeste Azimute  igual a 270\n");
        p1x = 0;
        p1y = 0;
        p2x = -1;
        p2y = 0;
        dd2gms(azimute_puissant( p1x, p1y, p2x, p2y));

        
}
