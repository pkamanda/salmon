#ifndef ALEVIN_OPTS_HPP
#define ALEVIN_OPTS_HPP

#include <string>
#include "spdlog/spdlog.h"
#include <boost/filesystem.hpp>

/**
  * A structure to hold some common options used
  * by Salmon so that we don't have to pass them
  * all around as separate arguments.
  */

enum class BarcodeEnd { FIVE = 5, THREE = 3 };
enum class Sequence { BARCODE, UMI };

template <class protocolT>
struct AlevinOpts {
  AlevinOpts(): numParsingThreads(1),
                numConsumerThreads(2),
                freqThreshold(10){}

  //IUPAC code for the cell-barcodes
  std::string iupac;
  //protocol to use for single cell
  protocolT protocol;
  //Dump soft-mapping of corrected barcodes
  bool dumpBarcodeMap;
  //umi_tools supported whitelist
  bool dumpUmiToolsMap;
  //dump barcodes fq files
  bool dumpfq;
  //dump CB features for whitelisting
  bool dumpfeatures;
  //flag for using barcoding or just single cell dedup
  bool nobarcode;
  //eqclass level barcode count
  bool dumpBarcodeEq;
  //dump cellvtxp matrix in csv
  bool dumpCsvCounts;
  // dump big fishing hash
  bool dumpBFH;
  // dump per cell level umi-graph
  bool dumpUmiGraph;
  //Stop progress sumps
  bool quiet;
  //flag for deduplication
  bool noDedup;
  //Number of generator threads
  uint32_t numParsingThreads;
  //Number of consumer threads
  uint32_t numConsumerThreads;
  //total num of threads
  uint32_t numThreads;
  //threshold for the frequency of the barcodes
  uint32_t freqThreshold;
  // sequences to trim from right in the read sequences
  uint32_t trimRight;
  //no downstream salmon quant
  bool noQuant;
  // use correlation for white-listing
  bool useCorrelation;
  // don't run EM flag
  bool noEM;
  // Avoid segfaults based on no whitelist mapping
  bool debug;
  // perform naive deduplication
  bool naiveEqclass;
  // perform eqclass level analysis instead of gene or txp level minsets
  bool eqClassLevel;
  // perform txp level analysis instead of gene level
  bool txpLevel;
  //do hard-assignment of error bcs
  bool noSoftMap;
  //number of cells
  uint32_t numCells;
  // minimum number of CB to use for low confidence region
  uint32_t lowRegionMinNumBarcodes;
  // maximum number of barcodes to use
  uint32_t maxNumBarcodes;
  // number of bootstraps to perform
  uint32_t numBootstraps;
  // force the number of cells
  uint32_t forceCells;
  // define a close upper bound on expected number of cells
  uint32_t expectCells;

  // Related to the logger
  std::shared_ptr<spdlog::logger> jointLog{nullptr};

  // barcode output directory
  boost::filesystem::path outputDirectory;
  // barcode white-list File path
  boost::filesystem::path whitelistFile;
  // barcode mitochondrial genes File path
  boost::filesystem::path mRnaFile;
  // barcode ribosomal gene File path
  boost::filesystem::path rRnaFile;
  // Txp to gene map tsv file
  boost::filesystem::path geneMapFile;
};

#endif // ALEVIN_OPTS_HPP
