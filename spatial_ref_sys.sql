SELECT srid, auth_name, auth_srid, srtext, proj4text
  FROM spatial_ref_sys where proj4text ='+proj=longlat +ellps=aust_SA +towgs84=-67.35,3.88,-38.22,0,0,0,0 +no_defs ';
