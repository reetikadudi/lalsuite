/* cmdline.h */

/* File autogenerated by gengetopt version 2.18  */

#ifndef CMDLINE_H
#define CMDLINE_H

/* If we use autoconf.  */
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifndef CMDLINE_PARSER_PACKAGE
#define CMDLINE_PARSER_PACKAGE PACKAGE
#endif

#ifndef CMDLINE_PARSER_VERSION
#define CMDLINE_PARSER_VERSION VERSION
#endif

struct gengetopt_args_info
{
  const char *help_help; /* Print help and exit help description.  */
  const char *version_help; /* Print version and exit help description.  */
  char * config_arg;	/* configuration file (in gengetopt format) to pass parameters.  */
  char * config_orig;	/* configuration file (in gengetopt format) to pass parameters original value given at command line.  */
  const char *config_help; /* configuration file (in gengetopt format) to pass parameters help description.  */
  char * label_arg;	/* arbitrary string to be printed in the beginning of PowerFlux log file.  */
  char * label_orig;	/* arbitrary string to be printed in the beginning of PowerFlux log file original value given at command line.  */
  const char *label_help; /* arbitrary string to be printed in the beginning of PowerFlux log file help description.  */
  char * sky_grid_arg;	/* sky grid type (arcsin, plain_rectangular, sin_theta) (default='sin_theta').  */
  char * sky_grid_orig;	/* sky grid type (arcsin, plain_rectangular, sin_theta) original value given at command line.  */
  const char *sky_grid_help; /* sky grid type (arcsin, plain_rectangular, sin_theta) help description.  */
  char * skymap_orientation_arg;	/* orientation of produced skymaps: equatorial, ecliptic, band_axis (default='equatorial').  */
  char * skymap_orientation_orig;	/* orientation of produced skymaps: equatorial, ecliptic, band_axis original value given at command line.  */
  const char *skymap_orientation_help; /* orientation of produced skymaps: equatorial, ecliptic, band_axis help description.  */
  char * skyband_method_arg;	/* method of assigning band numbers: angle, S (default='S').  */
  char * skyband_method_orig;	/* method of assigning band numbers: angle, S original value given at command line.  */
  const char *skyband_method_help; /* method of assigning band numbers: angle, S help description.  */
  int nskybands_arg;	/* split sky in this many bands for logging maximum upper limits (default='11').  */
  char * nskybands_orig;	/* split sky in this many bands for logging maximum upper limits original value given at command line.  */
  const char *nskybands_help; /* split sky in this many bands for logging maximum upper limits help description.  */
  double large_S_arg;	/* value of S to consider good enough.  */
  char * large_S_orig;	/* value of S to consider good enough original value given at command line.  */
  const char *large_S_help; /* value of S to consider good enough help description.  */
  char * band_axis_arg;	/* which band axis to use for splitting sky into bands (perpendicular to band axis) (possible values: equatorial, auto, explicit(float,float,float) (default='auto').  */
  char * band_axis_orig;	/* which band axis to use for splitting sky into bands (perpendicular to band axis) (possible values: equatorial, auto, explicit(float,float,float) original value given at command line.  */
  const char *band_axis_help; /* which band axis to use for splitting sky into bands (perpendicular to band axis) (possible values: equatorial, auto, explicit(float,float,float) help description.  */
  double band_axis_norm_arg;	/* norm of band axis vector to use in S value calculation.  */
  char * band_axis_norm_orig;	/* norm of band axis vector to use in S value calculation original value given at command line.  */
  const char *band_axis_norm_help; /* norm of band axis vector to use in S value calculation help description.  */
  char * sky_marks_file_arg;	/* file describing how to mark up a sky.  */
  char * sky_marks_file_orig;	/* file describing how to mark up a sky original value given at command line.  */
  const char *sky_marks_file_help; /* file describing how to mark up a sky help description.  */
  int fine_factor_arg;	/* make fine grid this times finer (default='5').  */
  char * fine_factor_orig;	/* make fine grid this times finer original value given at command line.  */
  const char *fine_factor_help; /* make fine grid this times finer help description.  */
  double skymap_resolution_arg;	/* specify skymap resolution explicitly.  */
  char * skymap_resolution_orig;	/* specify skymap resolution explicitly original value given at command line.  */
  const char *skymap_resolution_help; /* specify skymap resolution explicitly help description.  */
  double skymap_resolution_ratio_arg;	/* adjust default coarseness of the grid by this factor (default='1.0').  */
  char * skymap_resolution_ratio_orig;	/* adjust default coarseness of the grid by this factor original value given at command line.  */
  const char *skymap_resolution_ratio_help; /* adjust default coarseness of the grid by this factor help description.  */
  double small_weight_ratio_arg;	/* ratio that determines which weight is too small to include in max statistics (default='0.2').  */
  char * small_weight_ratio_orig;	/* ratio that determines which weight is too small to include in max statistics original value given at command line.  */
  const char *small_weight_ratio_help; /* ratio that determines which weight is too small to include in max statistics help description.  */
  double strain_norm_factor_arg;	/* strain normalization factor to prevent overflowing of the exponent (default='1e-20').  */
  char * strain_norm_factor_orig;	/* strain normalization factor to prevent overflowing of the exponent original value given at command line.  */
  const char *strain_norm_factor_help; /* strain normalization factor to prevent overflowing of the exponent help description.  */
  char * lock_file_arg;	/* file to lock when reading SFTs in order to globally serialize disk access.  */
  char * lock_file_orig;	/* file to lock when reading SFTs in order to globally serialize disk access original value given at command line.  */
  const char *lock_file_help; /* file to lock when reading SFTs in order to globally serialize disk access help description.  */
  int enable_dataset_locking_arg;	/* set to 1 to enable dataset level locking (default='0').  */
  char * enable_dataset_locking_orig;	/* set to 1 to enable dataset level locking original value given at command line.  */
  const char *enable_dataset_locking_help; /* set to 1 to enable dataset level locking help description.  */
  char * dataset_arg;	/* dataset file.  */
  char * dataset_orig;	/* dataset file original value given at command line.  */
  const char *dataset_help; /* dataset file help description.  */
  char * input_format_arg;	/* format of input files (GEO, SFT, Power) (default='GEO').  */
  char * input_format_orig;	/* format of input files (GEO, SFT, Power) original value given at command line.  */
  const char *input_format_help; /* format of input files (GEO, SFT, Power) help description.  */
  char * dump_data_arg;	/* file to output loaded SFT data into, for testing.  */
  char * dump_data_orig;	/* file to output loaded SFT data into, for testing original value given at command line.  */
  const char *dump_data_help; /* file to output loaded SFT data into, for testing help description.  */
  char * dump_sftv2_arg;	/* directory to output loaded data, together with dataset description.  */
  char * dump_sftv2_orig;	/* directory to output loaded data, together with dataset description original value given at command line.  */
  const char *dump_sftv2_help; /* directory to output loaded data, together with dataset description help description.  */
  char * output_arg;	/* output directory.  */
  char * output_orig;	/* output directory original value given at command line.  */
  const char *output_help; /* output directory help description.  */
  char * ephemeris_path_arg;	/* path to detresponse program from lalapps.  */
  char * ephemeris_path_orig;	/* path to detresponse program from lalapps original value given at command line.  */
  const char *ephemeris_path_help; /* path to detresponse program from lalapps help description.  */
  char * earth_ephemeris_arg;	/* Earth ephemeris file, overrides ephemeris-path argument.  */
  char * earth_ephemeris_orig;	/* Earth ephemeris file, overrides ephemeris-path argument original value given at command line.  */
  const char *earth_ephemeris_help; /* Earth ephemeris file, overrides ephemeris-path argument help description.  */
  char * sun_ephemeris_arg;	/* Sun ephemeris file, overrides ephemeris-path argument.  */
  char * sun_ephemeris_orig;	/* Sun ephemeris file, overrides ephemeris-path argument original value given at command line.  */
  const char *sun_ephemeris_help; /* Sun ephemeris file, overrides ephemeris-path argument help description.  */
  int first_bin_arg;	/* first frequency bin in the band to be analyzed.  */
  char * first_bin_orig;	/* first frequency bin in the band to be analyzed original value given at command line.  */
  const char *first_bin_help; /* first frequency bin in the band to be analyzed help description.  */
  int nbins_arg;	/* number of frequency bins to analyze (default='501').  */
  char * nbins_orig;	/* number of frequency bins to analyze original value given at command line.  */
  const char *nbins_help; /* number of frequency bins to analyze help description.  */
  int side_cut_arg;	/* number of bins to cut from each side due to corruption from doppler shifts.  */
  char * side_cut_orig;	/* number of bins to cut from each side due to corruption from doppler shifts original value given at command line.  */
  const char *side_cut_help; /* number of bins to cut from each side due to corruption from doppler shifts help description.  */
  int expected_timebase_arg;	/* expected timebase in months (default='6').  */
  char * expected_timebase_orig;	/* expected timebase in months original value given at command line.  */
  const char *expected_timebase_help; /* expected timebase in months help description.  */
  int hist_bins_arg;	/* number of bins to use when producing histograms (default='200').  */
  char * hist_bins_orig;	/* number of bins to use when producing histograms original value given at command line.  */
  const char *hist_bins_help; /* number of bins to use when producing histograms help description.  */
  char * detector_arg;	/* detector location (i.e. LHO or LLO), passed to detresponse.  */
  char * detector_orig;	/* detector location (i.e. LHO or LLO), passed to detresponse original value given at command line.  */
  const char *detector_help; /* detector location (i.e. LHO or LLO), passed to detresponse help description.  */
  double spindown_start_time_arg;	/* specify spindown start time in GPS sec. Assumed to be the first SFT segment by default.  */
  char * spindown_start_time_orig;	/* specify spindown start time in GPS sec. Assumed to be the first SFT segment by default original value given at command line.  */
  const char *spindown_start_time_help; /* specify spindown start time in GPS sec. Assumed to be the first SFT segment by default help description.  */
  double spindown_start_arg;	/* first spindown value to process (default='0.0').  */
  char * spindown_start_orig;	/* first spindown value to process original value given at command line.  */
  const char *spindown_start_help; /* first spindown value to process help description.  */
  double spindown_step_arg;	/* step for processing multiple spindown values (default='5e-10').  */
  char * spindown_step_orig;	/* step for processing multiple spindown values original value given at command line.  */
  const char *spindown_step_help; /* step for processing multiple spindown values help description.  */
  int spindown_count_arg;	/* how many separate spindown values to process (default='1').  */
  char * spindown_count_orig;	/* how many separate spindown values to process original value given at command line.  */
  const char *spindown_count_help; /* how many separate spindown values to process help description.  */
  double orientation_arg;	/* additional orientation phase, specifying 0.7853 will turn plus into cross (default='0').  */
  char * orientation_orig;	/* additional orientation phase, specifying 0.7853 will turn plus into cross original value given at command line.  */
  const char *orientation_help; /* additional orientation phase, specifying 0.7853 will turn plus into cross help description.  */
  int nlinear_polarizations_arg;	/* even number of linear polarizations to profile, distributed uniformly between 0 and PI/2 (default='4').  */
  char * nlinear_polarizations_orig;	/* even number of linear polarizations to profile, distributed uniformly between 0 and PI/2 original value given at command line.  */
  const char *nlinear_polarizations_help; /* even number of linear polarizations to profile, distributed uniformly between 0 and PI/2 help description.  */
  int no_demodulation_arg;	/* do not perform demodulation stage, analyze background only (default='0').  */
  char * no_demodulation_orig;	/* do not perform demodulation stage, analyze background only original value given at command line.  */
  const char *no_demodulation_help; /* do not perform demodulation stage, analyze background only help description.  */
  int no_decomposition_arg;	/* do not perform noise decomposition stage, output simple statistics only (default='0').  */
  char * no_decomposition_orig;	/* do not perform noise decomposition stage, output simple statistics only original value given at command line.  */
  const char *no_decomposition_help; /* do not perform noise decomposition stage, output simple statistics only help description.  */
  int no_candidates_arg;	/* do not perform analysis to identify candidates (default='0').  */
  char * no_candidates_orig;	/* do not perform analysis to identify candidates original value given at command line.  */
  const char *no_candidates_help; /* do not perform analysis to identify candidates help description.  */
  int no_am_response_arg;	/* force AM_response() function to return 1.0 irrespective of the arguments (default='0').  */
  char * no_am_response_orig;	/* force AM_response() function to return 1.0 irrespective of the arguments original value given at command line.  */
  const char *no_am_response_help; /* force AM_response() function to return 1.0 irrespective of the arguments help description.  */
  char * averaging_mode_arg;	/* 1 - use one bin, 3 - average 3, matched - use 7 bin matched filter (default='1').  */
  char * averaging_mode_orig;	/* 1 - use one bin, 3 - average 3, matched - use 7 bin matched filter original value given at command line.  */
  const char *averaging_mode_help; /* 1 - use one bin, 3 - average 3, matched - use 7 bin matched filter help description.  */
  int subtract_background_arg;	/* subtract rank 1 matrix in order to flatten noise spectrum (default='0').  */
  char * subtract_background_orig;	/* subtract rank 1 matrix in order to flatten noise spectrum original value given at command line.  */
  const char *subtract_background_help; /* subtract rank 1 matrix in order to flatten noise spectrum help description.  */
  int do_cutoff_arg;	/* neglect contribution from SFT with high effective noise level (default='1').  */
  char * do_cutoff_orig;	/* neglect contribution from SFT with high effective noise level original value given at command line.  */
  const char *do_cutoff_help; /* neglect contribution from SFT with high effective noise level help description.  */
  int filter_lines_arg;	/* perform detection of lines in background noise and veto corresponding frequency bins (default='1').  */
  char * filter_lines_orig;	/* perform detection of lines in background noise and veto corresponding frequency bins original value given at command line.  */
  const char *filter_lines_help; /* perform detection of lines in background noise and veto corresponding frequency bins help description.  */
  int ks_test_arg;	/* perform Kolmogorov-Smirnov test for normality of averaged powers (default='1').  */
  char * ks_test_orig;	/* perform Kolmogorov-Smirnov test for normality of averaged powers original value given at command line.  */
  const char *ks_test_help; /* perform Kolmogorov-Smirnov test for normality of averaged powers help description.  */
  int compute_betas_arg;	/* compute beta coefficients as described in PowerFlux polarizations document (default='0').  */
  char * compute_betas_orig;	/* compute beta coefficients as described in PowerFlux polarizations document original value given at command line.  */
  const char *compute_betas_help; /* compute beta coefficients as described in PowerFlux polarizations document help description.  */
  char * upper_limit_comp_arg;	/* upper limit compensation factor - used to account for windowing in SFTs (possible values: Hann, flat, arbitrary number) (default='Hann').  */
  char * upper_limit_comp_orig;	/* upper limit compensation factor - used to account for windowing in SFTs (possible values: Hann, flat, arbitrary number) original value given at command line.  */
  const char *upper_limit_comp_help; /* upper limit compensation factor - used to account for windowing in SFTs (possible values: Hann, flat, arbitrary number) help description.  */
  char * lower_limit_comp_arg;	/* lower limit compensation factor - used to account for windowing in SFTs (possible values: Hann, flat, arbitrary number) (default='Hann').  */
  char * lower_limit_comp_orig;	/* lower limit compensation factor - used to account for windowing in SFTs (possible values: Hann, flat, arbitrary number) original value given at command line.  */
  const char *lower_limit_comp_help; /* lower limit compensation factor - used to account for windowing in SFTs (possible values: Hann, flat, arbitrary number) help description.  */
  char * write_dat_arg;	/* regular expression describing which *.dat files to write (default='.*').  */
  char * write_dat_orig;	/* regular expression describing which *.dat files to write original value given at command line.  */
  const char *write_dat_help; /* regular expression describing which *.dat files to write help description.  */
  char * write_png_arg;	/* regular expression describing which *.png files to write (default='.*').  */
  char * write_png_orig;	/* regular expression describing which *.png files to write original value given at command line.  */
  const char *write_png_help; /* regular expression describing which *.png files to write help description.  */
  int dump_points_arg;	/* output averaged power bins for each point in the sky (default='0').  */
  char * dump_points_orig;	/* output averaged power bins for each point in the sky original value given at command line.  */
  const char *dump_points_help; /* output averaged power bins for each point in the sky help description.  */
  int dump_candidates_arg;	/* output SFT data for first N candidates (default='0').  */
  char * dump_candidates_orig;	/* output SFT data for first N candidates original value given at command line.  */
  const char *dump_candidates_help; /* output SFT data for first N candidates help description.  */
  double focus_ra_arg;	/* focus computation on a circular area with center at this RA.  */
  char * focus_ra_orig;	/* focus computation on a circular area with center at this RA original value given at command line.  */
  const char *focus_ra_help; /* focus computation on a circular area with center at this RA help description.  */
  double focus_dec_arg;	/* focus computation on a circular area with center at this DEC.  */
  char * focus_dec_orig;	/* focus computation on a circular area with center at this DEC original value given at command line.  */
  const char *focus_dec_help; /* focus computation on a circular area with center at this DEC help description.  */
  double focus_radius_arg;	/* focus computation on a circular area with this radius.  */
  char * focus_radius_orig;	/* focus computation on a circular area with this radius original value given at command line.  */
  const char *focus_radius_help; /* focus computation on a circular area with this radius help description.  */
  double only_large_cos_arg;	/* restrict computation to points on the sky with cos of angle to band axis larger than a given number.  */
  char * only_large_cos_orig;	/* restrict computation to points on the sky with cos of angle to band axis larger than a given number original value given at command line.  */
  const char *only_large_cos_help; /* restrict computation to points on the sky with cos of angle to band axis larger than a given number help description.  */
  const char *fake_linear_help; /* Inject linearly polarized fake signal help description.  */
  const char *fake_circular_help; /* Inject circularly polarized fake signal help description.  */
  double fake_ref_time_arg;	/* time of signal start (default='0').  */
  char * fake_ref_time_orig;	/* time of signal start original value given at command line.  */
  const char *fake_ref_time_help; /* time of signal start help description.  */
  double fake_ra_arg;	/* RA of fake signal to inject (default='3.14').  */
  char * fake_ra_orig;	/* RA of fake signal to inject original value given at command line.  */
  const char *fake_ra_help; /* RA of fake signal to inject help description.  */
  double fake_dec_arg;	/* DEC of fake signal to inject (default='0.0').  */
  char * fake_dec_orig;	/* DEC of fake signal to inject original value given at command line.  */
  const char *fake_dec_help; /* DEC of fake signal to inject help description.  */
  double fake_iota_arg;	/* iota of fake signal to inject (default='0.0').  */
  char * fake_iota_orig;	/* iota of fake signal to inject original value given at command line.  */
  const char *fake_iota_help; /* iota of fake signal to inject help description.  */
  double fake_psi_arg;	/* orientation of fake signal to inject (default='0.0').  */
  char * fake_psi_orig;	/* orientation of fake signal to inject original value given at command line.  */
  const char *fake_psi_help; /* orientation of fake signal to inject help description.  */
  double fake_phi_arg;	/* iota of fake signal to inject (default='0.0').  */
  char * fake_phi_orig;	/* iota of fake signal to inject original value given at command line.  */
  const char *fake_phi_help; /* iota of fake signal to inject help description.  */
  double fake_spindown_arg;	/* spindown of fake signal to inject (default='0.0').  */
  char * fake_spindown_orig;	/* spindown of fake signal to inject original value given at command line.  */
  const char *fake_spindown_help; /* spindown of fake signal to inject help description.  */
  double fake_strain_arg;	/* amplitude of fake signal to inject (default='1e-23').  */
  char * fake_strain_orig;	/* amplitude of fake signal to inject original value given at command line.  */
  const char *fake_strain_help; /* amplitude of fake signal to inject help description.  */
  double fake_freq_arg;	/* frequency of fake signal to inject.  */
  char * fake_freq_orig;	/* frequency of fake signal to inject original value given at command line.  */
  const char *fake_freq_help; /* frequency of fake signal to inject help description.  */
  double snr_precision_arg;	/* Assumed level of error in detection strength - used for listing candidates (default='0.2').  */
  char * snr_precision_orig;	/* Assumed level of error in detection strength - used for listing candidates original value given at command line.  */
  const char *snr_precision_help; /* Assumed level of error in detection strength - used for listing candidates help description.  */
  int max_candidates_arg;	/* Do not optimize more than this number of candidates (default='-1').  */
  char * max_candidates_orig;	/* Do not optimize more than this number of candidates original value given at command line.  */
  const char *max_candidates_help; /* Do not optimize more than this number of candidates help description.  */
  double min_candidate_snr_arg;	/* Do not optimize candidates with SNR below this level (default='5.0').  */
  char * min_candidate_snr_orig;	/* Do not optimize candidates with SNR below this level original value given at command line.  */
  const char *min_candidate_snr_help; /* Do not optimize candidates with SNR below this level help description.  */
  int output_initial_arg;	/* write initial candidates into log file (default='0').  */
  char * output_initial_orig;	/* write initial candidates into log file original value given at command line.  */
  const char *output_initial_help; /* write initial candidates into log file help description.  */
  int output_optimized_arg;	/* write optimized (second pass) candidates into log file (default='0').  */
  char * output_optimized_orig;	/* write optimized (second pass) candidates into log file original value given at command line.  */
  const char *output_optimized_help; /* write optimized (second pass) candidates into log file help description.  */
  int extended_test_arg;	/* Perform extended self test (default='0').  */
  char * extended_test_orig;	/* Perform extended self test original value given at command line.  */
  const char *extended_test_help; /* Perform extended self test help description.  */
  int num_threads_arg;	/* Use that many threads for computation (default='-1').  */
  char * num_threads_orig;	/* Use that many threads for computation original value given at command line.  */
  const char *num_threads_help; /* Use that many threads for computation help description.  */
  
  int help_given ;	/* Whether help was given.  */
  int version_given ;	/* Whether version was given.  */
  int config_given ;	/* Whether config was given.  */
  int label_given ;	/* Whether label was given.  */
  int sky_grid_given ;	/* Whether sky-grid was given.  */
  int skymap_orientation_given ;	/* Whether skymap-orientation was given.  */
  int skyband_method_given ;	/* Whether skyband-method was given.  */
  int nskybands_given ;	/* Whether nskybands was given.  */
  int large_S_given ;	/* Whether large-S was given.  */
  int band_axis_given ;	/* Whether band-axis was given.  */
  int band_axis_norm_given ;	/* Whether band-axis-norm was given.  */
  int sky_marks_file_given ;	/* Whether sky-marks-file was given.  */
  int fine_factor_given ;	/* Whether fine-factor was given.  */
  int skymap_resolution_given ;	/* Whether skymap-resolution was given.  */
  int skymap_resolution_ratio_given ;	/* Whether skymap-resolution-ratio was given.  */
  int small_weight_ratio_given ;	/* Whether small-weight-ratio was given.  */
  int strain_norm_factor_given ;	/* Whether strain-norm-factor was given.  */
  int lock_file_given ;	/* Whether lock-file was given.  */
  int enable_dataset_locking_given ;	/* Whether enable-dataset-locking was given.  */
  int dataset_given ;	/* Whether dataset was given.  */
  int input_format_given ;	/* Whether input-format was given.  */
  int dump_data_given ;	/* Whether dump-data was given.  */
  int dump_sftv2_given ;	/* Whether dump-sftv2 was given.  */
  int output_given ;	/* Whether output was given.  */
  int ephemeris_path_given ;	/* Whether ephemeris-path was given.  */
  int earth_ephemeris_given ;	/* Whether earth-ephemeris was given.  */
  int sun_ephemeris_given ;	/* Whether sun-ephemeris was given.  */
  int first_bin_given ;	/* Whether first-bin was given.  */
  int nbins_given ;	/* Whether nbins was given.  */
  int side_cut_given ;	/* Whether side-cut was given.  */
  int expected_timebase_given ;	/* Whether expected-timebase was given.  */
  int hist_bins_given ;	/* Whether hist-bins was given.  */
  int detector_given ;	/* Whether detector was given.  */
  int spindown_start_time_given ;	/* Whether spindown-start-time was given.  */
  int spindown_start_given ;	/* Whether spindown-start was given.  */
  int spindown_step_given ;	/* Whether spindown-step was given.  */
  int spindown_count_given ;	/* Whether spindown-count was given.  */
  int orientation_given ;	/* Whether orientation was given.  */
  int nlinear_polarizations_given ;	/* Whether nlinear-polarizations was given.  */
  int no_demodulation_given ;	/* Whether no-demodulation was given.  */
  int no_decomposition_given ;	/* Whether no-decomposition was given.  */
  int no_candidates_given ;	/* Whether no-candidates was given.  */
  int no_am_response_given ;	/* Whether no-am-response was given.  */
  int averaging_mode_given ;	/* Whether averaging-mode was given.  */
  int subtract_background_given ;	/* Whether subtract-background was given.  */
  int do_cutoff_given ;	/* Whether do-cutoff was given.  */
  int filter_lines_given ;	/* Whether filter-lines was given.  */
  int ks_test_given ;	/* Whether ks-test was given.  */
  int compute_betas_given ;	/* Whether compute-betas was given.  */
  int upper_limit_comp_given ;	/* Whether upper-limit-comp was given.  */
  int lower_limit_comp_given ;	/* Whether lower-limit-comp was given.  */
  int write_dat_given ;	/* Whether write-dat was given.  */
  int write_png_given ;	/* Whether write-png was given.  */
  int dump_points_given ;	/* Whether dump-points was given.  */
  int dump_candidates_given ;	/* Whether dump-candidates was given.  */
  int focus_ra_given ;	/* Whether focus-ra was given.  */
  int focus_dec_given ;	/* Whether focus-dec was given.  */
  int focus_radius_given ;	/* Whether focus-radius was given.  */
  int only_large_cos_given ;	/* Whether only-large-cos was given.  */
  int fake_linear_given ;	/* Whether fake-linear was given.  */
  int fake_circular_given ;	/* Whether fake-circular was given.  */
  int fake_ref_time_given ;	/* Whether fake-ref-time was given.  */
  int fake_ra_given ;	/* Whether fake-ra was given.  */
  int fake_dec_given ;	/* Whether fake-dec was given.  */
  int fake_iota_given ;	/* Whether fake-iota was given.  */
  int fake_psi_given ;	/* Whether fake-psi was given.  */
  int fake_phi_given ;	/* Whether fake-phi was given.  */
  int fake_spindown_given ;	/* Whether fake-spindown was given.  */
  int fake_strain_given ;	/* Whether fake-strain was given.  */
  int fake_freq_given ;	/* Whether fake-freq was given.  */
  int snr_precision_given ;	/* Whether snr-precision was given.  */
  int max_candidates_given ;	/* Whether max-candidates was given.  */
  int min_candidate_snr_given ;	/* Whether min-candidate-snr was given.  */
  int output_initial_given ;	/* Whether output-initial was given.  */
  int output_optimized_given ;	/* Whether output-optimized was given.  */
  int extended_test_given ;	/* Whether extended-test was given.  */
  int num_threads_given ;	/* Whether num-threads was given.  */

  int injection_group_counter; /* counter for group injection */
} ;

extern const char *gengetopt_args_info_purpose;
extern const char *gengetopt_args_info_usage;
extern const char *gengetopt_args_info_help[];

int cmdline_parser (int argc, char * const *argv,
  struct gengetopt_args_info *args_info);
int cmdline_parser2 (int argc, char * const *argv,
  struct gengetopt_args_info *args_info,
  int override, int initialize, int check_required);
int cmdline_parser_file_save(const char *filename,
  struct gengetopt_args_info *args_info);

void cmdline_parser_print_help(void);
void cmdline_parser_print_version(void);

void cmdline_parser_init (struct gengetopt_args_info *args_info);
void cmdline_parser_free (struct gengetopt_args_info *args_info);

int cmdline_parser_configfile (char * const filename,
  struct gengetopt_args_info *args_info,
  int override, int initialize, int check_required);

int cmdline_parser_required (struct gengetopt_args_info *args_info,
  const char *prog_name);


#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* CMDLINE_H */
