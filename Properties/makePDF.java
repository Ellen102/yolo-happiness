package main;

import com.itextpdf.text.Document;
import com.itextpdf.text.DocumentException;
import com.itextpdf.text.pdf.PdfCopy;
import com.itextpdf.text.pdf.PdfReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.Collection;
import java.util.List;
import java.util.Properties;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Ellen
 */
public class Main {

    private static final String prop = "C:\\Users\\Ellen\\Documents\\CoderDojo\\git\\yolo-happiness\\Properties\\scratch.properties";
    /**
     * @param args the command line arguments
     *
     * @throws java.io.FileNotFoundException
     * @throws com.itextpdf.text.DocumentException
     */
    public static void main(String[] args) throws FileNotFoundException, DocumentException, IOException {
        Main main = new Main();
        /*  
         * @param args[0] outputfilename default: result_{}.pdf
         * @param args[1] txt with filenames default: files.txt
         if (args.length == 0) {
         //default
         main.createPdf("result_" + System.currentTimeMillis() + ".pdf", main.readTXT(DEFAULTXT));
         } else if (args.length == 1) {
         //outputfile
         main.createPdf(args[1], main.readTXT(DEFAULTXT));
         } else if (args.length == 2) {
         //outputfile & list
         main.createPdf(args[1], main.readTXT(args[2]));
         }*/
        if (args.length == 0) {
            main.makeListPdf(main.readProperties(prop));
        } else {
            main.makeListPdf(main.readProperties(args[0]));
        }

        
        

    }
    //private static final String DEFAULTXT = "C:\\Users\\Ellen\\Documents\\NetBeansProjects\\ConcatPDF\\src\\main\\resources\\files.txt";
    private static final String DEFAULTPROP = "C:\\Users\\Ellen\\Documents\\NetBeansProjects\\ConcatPDF\\src\\main\\resources\\files.properties";

    /**
     * read all filenames in a txt file
     *
     * @param filename
     * @return
     * @throws FileNotFoundException
     */
    public List<String> readTXT(String filename) throws FileNotFoundException {
        List<String> result = new ArrayList<>();
        try (Scanner inFile1 = new Scanner(new File(filename))) {
            String line;
            // while loop
            while (inFile1.hasNext()) {
                // find next line
                line = inFile1.next();
                result.add(line);
            }
        }

        return result;
    }

    /**
     *
     * @param filename
     * @return
     * @throws FileNotFoundException
     * @throws IOException
     */
    public List<projectInfo> readProperties(String filename) throws FileNotFoundException, IOException {
        Properties prop = new Properties();
        InputStream input = null;
        List<projectInfo> ret = new ArrayList<>();
        try {

            input = new FileInputStream(filename);

            // load a properties file
            prop.load(input);

            String[] list = prop.getProperty("files", "").split(",");
            for (String item : list) {
                //a_subfilefolder
                String folder = prop.getProperty(item + "_" + "subfilefolder", "");
                //result file
                String resultfile = prop.getProperty(item + "_" + "result", item + "_" + System.currentTimeMillis() + ".pdf");
                //subfiles
                List<String> result = new ArrayList<>();
                String[] files = prop.getProperty(item + "_" + "subfiles", "").split(",");
                for (String file : files) {
                    result.add(folder + file);
                }
                projectInfo p = new projectInfo(resultfile, result);
                p.print();
                ret.add(p);
                
            }

        } finally {
            if (input != null) {
                input.close();
            }
        }
        return ret;

    }

    public class projectInfo {

        private final String resultname;
        private final Collection<String> subfiles;

        public projectInfo(String resultname, Collection<String> subfiles) {
            this.resultname = resultname;
            this.subfiles = subfiles;
        }

        public String getResultname() {
            return resultname;
        }

        public Collection<String> getSubfiles() {
            return subfiles;
        }
        
        public void print(){
            System.out.println("result file:"+resultname);
            System.out.println("-subfiles:");
            for (String subfile : subfiles) {
                System.out.println("--"+subfile);
            }
        }

    }

    public void makeListPdf(Collection<projectInfo> projects) 
    {
        for (projectInfo project : projects) {
            try {
                createPdf(project.getResultname(), project.getSubfiles());
            } catch (DocumentException ex) {
                Logger.getLogger(Main.class.getName()).log(Level.SEVERE, null, ex);
            } catch (IOException ex) {
                Logger.getLogger(Main.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
    }

    /**
     * makes one pdf of all pdfs in the list
     *
     * @param filename
     * @param names
     * @throws DocumentException
     * @throws IOException
     */
    public void createPdf(String filename, Collection<String> names)
            throws DocumentException, IOException {
        // step 1
        Document document = new Document();
        document.addAuthor("Ellen Vanhove");
        document.addCreationDate();
        document.addTitle(filename.substring(0, filename.indexOf('.')));
        // step 2
        PdfCopy copy = new PdfCopy(document, new FileOutputStream(filename));
        // step 3
        document.open();
        // step 4
        PdfReader reader;
        int n;
        // loop over the documents you want to concatenate
        for (String name : names) {
            reader = new PdfReader(name);
            // loop over the pages in that document
            n = reader.getNumberOfPages();
            for (int page = 0; page < n;) {
                copy.addPage(copy.getImportedPage(reader, ++page));
            }
            copy.freeReader(reader);
            reader.close();
        }
        // step 5
        document.close();
    }

}
