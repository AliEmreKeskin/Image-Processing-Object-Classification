#pragma once
#include <Windows.h>
#include <atlstr.h>
#include "Imge.h"
#include <math.h>


using namespace std;

namespace ImageProcessing {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

		LPCTSTR input, output;
		int Width, Height;
		long Size;
		int imgSize;
		BYTE* buffer;
		BYTE* Raw_Intensity;
		BYTE* segmanted;
		int* tags;
		int* sortedTags;
		int numberOfObjects;
		BYTE* objColor;
		int* tagList;
		int* areas;
		BYTE* boundary;
		int* perimeters;
		float* thinnesses;
		int farea;
		float fthinness;
		int narea;
		float nthinness;
		int marea;
		float mthinness;
		int fas;
		int noh;
		int mer;
		int* classified;
		BYTE* show;



	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  openToolStripMenuItem;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::ToolStripMenuItem^  editToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ýntensityToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  showToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  histogramToolStripMenuItem;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  chart1;
	private: System::Windows::Forms::ToolStripMenuItem^  equalizeHistogramToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  kMeansToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  kMeansToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  ýntencityToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  euclideanToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  mahalanobisToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  rGBToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  euclideanToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  mahalanobisToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  morpholoToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  dilationToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  erosionToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  openToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  closeToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  boundryExtractionToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  connectedComponentAnalysisToolStripMenuItem;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::ToolStripMenuItem^  featureExtractionToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  objectsÝnDifferentColorsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  areaToolStripMenuItem;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::ListBox^  listBox1;
	private: System::Windows::Forms::ToolStripMenuItem^  thinnessRatioToolStripMenuItem;
	private: System::Windows::Forms::ListBox^  listBox2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::ToolStripMenuItem^  saveToolStripMenuItem;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::RichTextBox^  richTextBox1;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::RichTextBox^  richTextBox2;
	private: System::Windows::Forms::ToolStripMenuItem^  prosedureOneToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  prosedureTwoToolStripMenuItem;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::Button^  button8;
	private: System::Windows::Forms::Button^  button9;
	private: System::Windows::Forms::Label^  label4;



#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->editToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ýntensityToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->equalizeHistogramToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->kMeansToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->kMeansToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ýntencityToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->euclideanToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mahalanobisToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->rGBToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->euclideanToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mahalanobisToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->morpholoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->dilationToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->erosionToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->closeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->boundryExtractionToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->showToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->histogramToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->connectedComponentAnalysisToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->objectsÝnDifferentColorsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->featureExtractionToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->areaToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->thinnessRatioToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->prosedureOneToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->prosedureTwoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->listBox2 = (gcnew System::Windows::Forms::ListBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->richTextBox2 = (gcnew System::Windows::Forms::RichTextBox());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {
				this->fileToolStripMenuItem,
					this->editToolStripMenuItem, this->showToolStripMenuItem, this->featureExtractionToolStripMenuItem, this->prosedureOneToolStripMenuItem,
					this->prosedureTwoToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1310, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->openToolStripMenuItem,
					this->saveToolStripMenuItem
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// openToolStripMenuItem
			// 
			this->openToolStripMenuItem->Name = L"openToolStripMenuItem";
			this->openToolStripMenuItem->Size = System::Drawing::Size(103, 22);
			this->openToolStripMenuItem->Text = L"Open";
			this->openToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::openToolStripMenuItem_Click);
			// 
			// saveToolStripMenuItem
			// 
			this->saveToolStripMenuItem->Name = L"saveToolStripMenuItem";
			this->saveToolStripMenuItem->Size = System::Drawing::Size(103, 22);
			this->saveToolStripMenuItem->Text = L"Save";
			this->saveToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::saveToolStripMenuItem_Click);
			// 
			// editToolStripMenuItem
			// 
			this->editToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->ýntensityToolStripMenuItem,
					this->equalizeHistogramToolStripMenuItem, this->kMeansToolStripMenuItem, this->morpholoToolStripMenuItem, this->boundryExtractionToolStripMenuItem
			});
			this->editToolStripMenuItem->Name = L"editToolStripMenuItem";
			this->editToolStripMenuItem->Size = System::Drawing::Size(39, 20);
			this->editToolStripMenuItem->Text = L"Edit";
			// 
			// ýntensityToolStripMenuItem
			// 
			this->ýntensityToolStripMenuItem->Name = L"ýntensityToolStripMenuItem";
			this->ýntensityToolStripMenuItem->Size = System::Drawing::Size(190, 22);
			this->ýntensityToolStripMenuItem->Text = L"Intensity";
			this->ýntensityToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::ýntensityToolStripMenuItem_Click);
			// 
			// equalizeHistogramToolStripMenuItem
			// 
			this->equalizeHistogramToolStripMenuItem->Name = L"equalizeHistogramToolStripMenuItem";
			this->equalizeHistogramToolStripMenuItem->ShowShortcutKeys = false;
			this->equalizeHistogramToolStripMenuItem->Size = System::Drawing::Size(190, 22);
			this->equalizeHistogramToolStripMenuItem->Text = L"Histogram Equalization";
			this->equalizeHistogramToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::equalizeHistogramToolStripMenuItem_Click);
			// 
			// kMeansToolStripMenuItem
			// 
			this->kMeansToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->kMeansToolStripMenuItem1 });
			this->kMeansToolStripMenuItem->Name = L"kMeansToolStripMenuItem";
			this->kMeansToolStripMenuItem->Size = System::Drawing::Size(190, 22);
			this->kMeansToolStripMenuItem->Text = L"Segmantation";
			// 
			// kMeansToolStripMenuItem1
			// 
			this->kMeansToolStripMenuItem1->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->ýntencityToolStripMenuItem,
					this->rGBToolStripMenuItem
			});
			this->kMeansToolStripMenuItem1->Name = L"kMeansToolStripMenuItem1";
			this->kMeansToolStripMenuItem1->Size = System::Drawing::Size(121, 22);
			this->kMeansToolStripMenuItem1->Text = L"K-Means";
			// 
			// ýntencityToolStripMenuItem
			// 
			this->ýntencityToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->euclideanToolStripMenuItem,
					this->mahalanobisToolStripMenuItem
			});
			this->ýntencityToolStripMenuItem->Name = L"ýntencityToolStripMenuItem";
			this->ýntencityToolStripMenuItem->Size = System::Drawing::Size(120, 22);
			this->ýntencityToolStripMenuItem->Text = L"Intencity";
			// 
			// euclideanToolStripMenuItem
			// 
			this->euclideanToolStripMenuItem->Name = L"euclideanToolStripMenuItem";
			this->euclideanToolStripMenuItem->Size = System::Drawing::Size(142, 22);
			this->euclideanToolStripMenuItem->Text = L"Euclidean";
			this->euclideanToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::euclideanToolStripMenuItem_Click);
			// 
			// mahalanobisToolStripMenuItem
			// 
			this->mahalanobisToolStripMenuItem->Name = L"mahalanobisToolStripMenuItem";
			this->mahalanobisToolStripMenuItem->Size = System::Drawing::Size(142, 22);
			this->mahalanobisToolStripMenuItem->Text = L"Mahalanobis";
			this->mahalanobisToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::mahalanobisToolStripMenuItem_Click);
			// 
			// rGBToolStripMenuItem
			// 
			this->rGBToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->euclideanToolStripMenuItem1,
					this->mahalanobisToolStripMenuItem1
			});
			this->rGBToolStripMenuItem->Name = L"rGBToolStripMenuItem";
			this->rGBToolStripMenuItem->Size = System::Drawing::Size(120, 22);
			this->rGBToolStripMenuItem->Text = L"RGB";
			// 
			// euclideanToolStripMenuItem1
			// 
			this->euclideanToolStripMenuItem1->Name = L"euclideanToolStripMenuItem1";
			this->euclideanToolStripMenuItem1->Size = System::Drawing::Size(142, 22);
			this->euclideanToolStripMenuItem1->Text = L"Euclidean";
			// 
			// mahalanobisToolStripMenuItem1
			// 
			this->mahalanobisToolStripMenuItem1->Name = L"mahalanobisToolStripMenuItem1";
			this->mahalanobisToolStripMenuItem1->Size = System::Drawing::Size(142, 22);
			this->mahalanobisToolStripMenuItem1->Text = L"Mahalanobis";
			// 
			// morpholoToolStripMenuItem
			// 
			this->morpholoToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->dilationToolStripMenuItem,
					this->erosionToolStripMenuItem, this->openToolStripMenuItem1, this->closeToolStripMenuItem
			});
			this->morpholoToolStripMenuItem->Name = L"morpholoToolStripMenuItem";
			this->morpholoToolStripMenuItem->Size = System::Drawing::Size(190, 22);
			this->morpholoToolStripMenuItem->Text = L"Morphological";
			// 
			// dilationToolStripMenuItem
			// 
			this->dilationToolStripMenuItem->Name = L"dilationToolStripMenuItem";
			this->dilationToolStripMenuItem->Size = System::Drawing::Size(115, 22);
			this->dilationToolStripMenuItem->Text = L"Dilation";
			this->dilationToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::dilationToolStripMenuItem_Click);
			// 
			// erosionToolStripMenuItem
			// 
			this->erosionToolStripMenuItem->Name = L"erosionToolStripMenuItem";
			this->erosionToolStripMenuItem->Size = System::Drawing::Size(115, 22);
			this->erosionToolStripMenuItem->Text = L"Erosion";
			this->erosionToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::erosionToolStripMenuItem_Click);
			// 
			// openToolStripMenuItem1
			// 
			this->openToolStripMenuItem1->Name = L"openToolStripMenuItem1";
			this->openToolStripMenuItem1->Size = System::Drawing::Size(115, 22);
			this->openToolStripMenuItem1->Text = L"Open";
			this->openToolStripMenuItem1->Click += gcnew System::EventHandler(this, &MyForm::openToolStripMenuItem1_Click);
			// 
			// closeToolStripMenuItem
			// 
			this->closeToolStripMenuItem->Name = L"closeToolStripMenuItem";
			this->closeToolStripMenuItem->Size = System::Drawing::Size(115, 22);
			this->closeToolStripMenuItem->Text = L"Close";
			this->closeToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::closeToolStripMenuItem_Click);
			// 
			// boundryExtractionToolStripMenuItem
			// 
			this->boundryExtractionToolStripMenuItem->Name = L"boundryExtractionToolStripMenuItem";
			this->boundryExtractionToolStripMenuItem->Size = System::Drawing::Size(190, 22);
			this->boundryExtractionToolStripMenuItem->Text = L"Boundry Extraction";
			this->boundryExtractionToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::boundryExtractionToolStripMenuItem_Click);
			// 
			// showToolStripMenuItem
			// 
			this->showToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->histogramToolStripMenuItem,
					this->connectedComponentAnalysisToolStripMenuItem, this->objectsÝnDifferentColorsToolStripMenuItem
			});
			this->showToolStripMenuItem->Name = L"showToolStripMenuItem";
			this->showToolStripMenuItem->Size = System::Drawing::Size(48, 20);
			this->showToolStripMenuItem->Text = L"Show";
			// 
			// histogramToolStripMenuItem
			// 
			this->histogramToolStripMenuItem->Name = L"histogramToolStripMenuItem";
			this->histogramToolStripMenuItem->Size = System::Drawing::Size(245, 22);
			this->histogramToolStripMenuItem->Text = L"Histogram";
			this->histogramToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::histogramToolStripMenuItem_Click);
			// 
			// connectedComponentAnalysisToolStripMenuItem
			// 
			this->connectedComponentAnalysisToolStripMenuItem->Name = L"connectedComponentAnalysisToolStripMenuItem";
			this->connectedComponentAnalysisToolStripMenuItem->Size = System::Drawing::Size(245, 22);
			this->connectedComponentAnalysisToolStripMenuItem->Text = L"Connected Component Analysis";
			this->connectedComponentAnalysisToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::connectedComponentAnalysisToolStripMenuItem_Click);
			// 
			// objectsÝnDifferentColorsToolStripMenuItem
			// 
			this->objectsÝnDifferentColorsToolStripMenuItem->Name = L"objectsÝnDifferentColorsToolStripMenuItem";
			this->objectsÝnDifferentColorsToolStripMenuItem->Size = System::Drawing::Size(245, 22);
			this->objectsÝnDifferentColorsToolStripMenuItem->Text = L"Objects in Different Colors";
			this->objectsÝnDifferentColorsToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::objectsÝnDifferentColorsToolStripMenuItem_Click);
			// 
			// featureExtractionToolStripMenuItem
			// 
			this->featureExtractionToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->areaToolStripMenuItem,
					this->thinnessRatioToolStripMenuItem
			});
			this->featureExtractionToolStripMenuItem->Name = L"featureExtractionToolStripMenuItem";
			this->featureExtractionToolStripMenuItem->Size = System::Drawing::Size(113, 20);
			this->featureExtractionToolStripMenuItem->Text = L"Feature Extraction";
			// 
			// areaToolStripMenuItem
			// 
			this->areaToolStripMenuItem->Name = L"areaToolStripMenuItem";
			this->areaToolStripMenuItem->Size = System::Drawing::Size(151, 22);
			this->areaToolStripMenuItem->Text = L"Area";
			this->areaToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::areaToolStripMenuItem_Click);
			// 
			// thinnessRatioToolStripMenuItem
			// 
			this->thinnessRatioToolStripMenuItem->Name = L"thinnessRatioToolStripMenuItem";
			this->thinnessRatioToolStripMenuItem->Size = System::Drawing::Size(151, 22);
			this->thinnessRatioToolStripMenuItem->Text = L"Thinness Ratio";
			this->thinnessRatioToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::thinnessRatioToolStripMenuItem_Click);
			// 
			// prosedureOneToolStripMenuItem
			// 
			this->prosedureOneToolStripMenuItem->Name = L"prosedureOneToolStripMenuItem";
			this->prosedureOneToolStripMenuItem->Size = System::Drawing::Size(97, 20);
			this->prosedureOneToolStripMenuItem->Text = L"Prosedure One";
			this->prosedureOneToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::prosedureOneToolStripMenuItem_Click);
			// 
			// prosedureTwoToolStripMenuItem
			// 
			this->prosedureTwoToolStripMenuItem->Name = L"prosedureTwoToolStripMenuItem";
			this->prosedureTwoToolStripMenuItem->Size = System::Drawing::Size(97, 20);
			this->prosedureTwoToolStripMenuItem->Text = L"Prosedure Two";
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(13, 28);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(800, 450);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			// 
			// chart1
			// 
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(819, 28);
			this->chart1->Name = L"chart1";
			series1->ChartArea = L"ChartArea1";
			series1->Legend = L"Legend1";
			series1->Name = L"Intensity";
			this->chart1->Series->Add(series1);
			this->chart1->Size = System::Drawing::Size(479, 295);
			this->chart1->TabIndex = 2;
			this->chart1->Text = L"Histogram";
			this->chart1->Visible = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(918, 326);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(98, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Number of Objects:";
			this->label1->Visible = false;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(819, 343);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(34, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Areas";
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Location = System::Drawing::Point(819, 359);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(120, 95);
			this->listBox1->TabIndex = 5;
			// 
			// listBox2
			// 
			this->listBox2->FormattingEnabled = true;
			this->listBox2->Location = System::Drawing::Point(946, 359);
			this->listBox2->Name = L"listBox2";
			this->listBox2->Size = System::Drawing::Size(120, 95);
			this->listBox2->TabIndex = 7;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(819, 326);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(93, 13);
			this->label3->TabIndex = 8;
			this->label3->Text = L"Number of Object:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(943, 343);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(61, 13);
			this->label4->TabIndex = 9;
			this->label4->Text = L"Thinnesses";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(13, 485);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(123, 20);
			this->textBox1->TabIndex = 10;
			this->textBox1->Text = L"Enter Number of Classes";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(143, 485);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 11;
			this->button1->Text = L"Classify";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(1207, 359);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(91, 23);
			this->button2->TabIndex = 12;
			this->button2->Text = L"save beans";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(1207, 388);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(91, 23);
			this->button3->TabIndex = 13;
			this->button3->Text = L"save chickpeas";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(1207, 417);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(91, 23);
			this->button4->TabIndex = 14;
			this->button4->Text = L"save lentils";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(819, 460);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(100, 96);
			this->richTextBox1->TabIndex = 15;
			this->richTextBox1->Text = L"";
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(1072, 431);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(75, 23);
			this->button5->TabIndex = 16;
			this->button5->Text = L"clear";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(925, 533);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(75, 23);
			this->button6->TabIndex = 17;
			this->button6->Text = L"Classify";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// richTextBox2
			// 
			this->richTextBox2->Location = System::Drawing::Point(1006, 460);
			this->richTextBox2->Name = L"richTextBox2";
			this->richTextBox2->Size = System::Drawing::Size(195, 96);
			this->richTextBox2->TabIndex = 18;
			this->richTextBox2->Text = L"";
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(1207, 460);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(91, 23);
			this->button7->TabIndex = 19;
			this->button7->Text = L"Show";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &MyForm::button7_Click);
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(1207, 489);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(91, 23);
			this->button8->TabIndex = 20;
			this->button8->Text = L"Show";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &MyForm::button8_Click);
			// 
			// button9
			// 
			this->button9->Location = System::Drawing::Point(1207, 518);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(91, 23);
			this->button9->TabIndex = 21;
			this->button9->Text = L"Show";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &MyForm::button9_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1310, 649);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->richTextBox2);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->listBox2);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->chart1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion



	private: System::Void openToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			pictureBox1->ImageLocation = openFileDialog1->FileName;
			CString str;
			str = openFileDialog1->FileName;
			input = (LPCTSTR)str;
			buffer = LoadBMP(Width, Height, Size, input);
			imgSize = Width * Height;
		}
	}	
	private: System::Void ýntensityToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		Raw_Intensity = ConvertBMPToIntensity(buffer, Width, Height);
		// picture
		{
			Bitmap^ surface = gcnew Bitmap(Width, Height);
			pictureBox1->Image = surface;
			Color c;
			int temp;
			for (unsigned int row = 0; row < Height; row++) {
				for (unsigned int column = 0; column < Width; column++) {
					temp = row*Width + column;
					c = Color::FromArgb(Raw_Intensity[temp], Raw_Intensity[temp], Raw_Intensity[temp]);
					surface->SetPixel(column, row, c);
				}
			}
		}
	}
	private: System::Void histogramToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		if (histogramToolStripMenuItem->CheckState == System::Windows::Forms::CheckState::Checked) {
			histogramToolStripMenuItem->CheckState = System::Windows::Forms::CheckState::Unchecked;
			chart1->Visible = false;
		}
		else {
			histogramToolStripMenuItem->CheckState = System::Windows::Forms::CheckState::Checked;
			chart1->Visible = true;
		}
		int* Histogram = getHistogram(Raw_Intensity, Width, Height);
		for (int i = 0; i < 256; i++) {
			chart1->Series["Intensity"]->Points->AddXY(i, Histogram[i]);
		}
	}
	private: System::Void equalizeHistogramToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		int* Histogram = getHistogram(Raw_Intensity, Width, Height);
		int* newValues = new int[256];
		float Sum = 0.0;
		float currentSum = 0.0;
		//calculate sum of histogram values
		for (int i = 0; i < 256; i++) {
			Sum += Histogram[i];
		}
		//produce equalized new values
		for (int i = 0; i < 256; i++) {
			currentSum += Histogram[i];
			newValues[i] = currentSum / Sum * 255;
		}
		//replace equalized values with not equalized old values
		for (int i = 0; i < Height; i++) {
			for (int j = 0; j < Width; j++) {
				Raw_Intensity[i*Width + j] = newValues[Raw_Intensity[i*Width + j]];
			}
		}
		// print pic
		{
			Bitmap^ surface = gcnew Bitmap(Width, Height);
			pictureBox1->Image = surface;
			Color c;
			int temp;
			for (unsigned int row = 0; row < Height; row++) {
				for (unsigned int column = 0; column < Width; column++) {
					temp = row*Width + column;
					c = Color::FromArgb(Raw_Intensity[temp], Raw_Intensity[temp], Raw_Intensity[temp]);
					surface->SetPixel(column, row, c);
				}
			}
		}
	}
	private: System::Void euclideanToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		int* Histogram = getHistogram(Raw_Intensity, Width, Height);
		segmanted = KMeans(Histogram, Raw_Intensity, Width*Height,5);

		// picture
		{
			Bitmap^ surface = gcnew Bitmap(Width, Height);
			pictureBox1->Image = surface;
			Color c;
			int temp;
			for (unsigned int row = 0; row < Height; row++) {
				for (unsigned int column = 0; column < Width; column++) {
					temp = row * Width + column;
					c = Color::FromArgb(segmanted[temp], segmanted[temp], segmanted[temp]);
					surface->SetPixel(column, row, c);
				}
			}
		}
	}
	private: System::Void mahalanobisToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		int* Histogram = getHistogram(Raw_Intensity, Width, Height);
		segmanted = Kmeans_Mahalanobis(Histogram, Raw_Intensity, Width*Height, 5);
		// picture
		{
			Bitmap^ surface = gcnew Bitmap(Width, Height);
			pictureBox1->Image = surface;
			Color c;
			int temp;
			for (unsigned int row = 0; row < Height; row++) {
				for (unsigned int column = 0; column < Width; column++) {
					temp = row * Width + column;
					c = Color::FromArgb(segmanted[temp], segmanted[temp], segmanted[temp]);
					surface->SetPixel(column, row, c);
				}
			}
		}
	}
	private: System::Void dilationToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		segmanted = Dilation(segmanted, Width, Height, 1);
		// picture
		{
			Bitmap^ surface = gcnew Bitmap(Width, Height);
			pictureBox1->Image = surface;
			Color c;
			int temp;
			for (unsigned int row = 0; row < Height; row++) {
				for (unsigned int column = 0; column < Width; column++) {
					temp = row * Width + column;
					c = Color::FromArgb(segmanted[temp], segmanted[temp], segmanted[temp]);
					surface->SetPixel(column, row, c);
				}
			}
		}
	}
	private: System::Void erosionToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		segmanted=Erosion(segmanted, Width, Height, 1);
		// picture
		{
			Bitmap^ surface = gcnew Bitmap(Width, Height);
			pictureBox1->Image = surface;
			Color c;
			int temp;
			for (unsigned int row = 0; row < Height; row++) {
				for (unsigned int column = 0; column < Width; column++) {
					temp = row * Width + column;
					c = Color::FromArgb(segmanted[temp], segmanted[temp], segmanted[temp]);
					surface->SetPixel(column, row, c);
				}
			}
		}
	}
	private: System::Void openToolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e) {
		segmanted = Erosion(segmanted, Width, Height, 1);
		segmanted = Dilation(segmanted, Width, Height, 1);
		// picture
		{
			Bitmap^ surface = gcnew Bitmap(Width, Height);
			pictureBox1->Image = surface;
			Color c;
			int temp;
			for (unsigned int row = 0; row < Height; row++) {
				for (unsigned int column = 0; column < Width; column++) {
					temp = row * Width + column;
					c = Color::FromArgb(segmanted[temp], segmanted[temp], segmanted[temp]);
					surface->SetPixel(column, row, c);
				}
			}
		}
	}
	private: System::Void closeToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		segmanted = Dilation(segmanted, Width, Height, 1);
		segmanted = Erosion(segmanted, Width, Height, 1);

		// picture
		{
			Bitmap^ surface = gcnew Bitmap(Width, Height);
			pictureBox1->Image = surface;
			Color c;
			int temp;
			for (unsigned int row = 0; row < Height; row++) {
				for (unsigned int column = 0; column < Width; column++) {
					temp = row * Width + column;
					c = Color::FromArgb(segmanted[temp], segmanted[temp], segmanted[temp]);
					surface->SetPixel(column, row, c);
				}
			}
		}
	}
	private: System::Void boundryExtractionToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		boundary = Boundary_Extraction(segmanted, Width, Height);
		// picture
		{
			Bitmap^ surface = gcnew Bitmap(Width, Height);
			pictureBox1->Image = surface;
			Color c;
			int temp;
			for (unsigned int row = 0; row < Height; row++) {
				for (unsigned int column = 0; column < Width; column++) {
					temp = row * Width + column;
					c = Color::FromArgb(boundary[temp], boundary[temp], boundary[temp]);
					surface->SetPixel(column, row, c);
				}
			}
		}
	}
	private: System::Void connectedComponentAnalysisToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		label1->Visible = true;
		tags = Create_Tags(segmanted, Width, Height, 8);
		sortedTags = Sort_Tags(tags, Width, Height);
		numberOfObjects = Count_Tags(sortedTags, imgSize);
		label1->Text = System::Convert::ToString(numberOfObjects);
		tagList = Create_TagList(sortedTags, numberOfObjects, imgSize);
	}
	private: System::Void objectsÝnDifferentColorsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {		
		objColor = Color_Objects(segmanted, sortedTags, tags, numberOfObjects, imgSize);
		// picture
		{
			Bitmap^ surface = gcnew Bitmap(Width, Height);
			pictureBox1->Image = surface;
			Color c;
			int temp;
			for (unsigned int row = 0; row < Height; row++) {
				for (unsigned int column = 0; column < Width; column++) {
					temp = row * Width + column;
					c = Color::FromArgb(objColor[temp], objColor[temp], objColor[temp]);
					surface->SetPixel(column, row, c);
				}
			}
		}
	}
	private: System::Void areaToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		areas = Area_Extraction(tags, tagList, numberOfObjects, imgSize);
		for (int i = 0; i < numberOfObjects; i++) {
			listBox1->Items->Add(areas[i]);
		}
	}
	private: System::Void thinnessRatioToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		perimeters = Perimeter_Extraction(segmanted, Width, Height);
		thinnesses = Thinness_Extraction(areas, perimeters, numberOfObjects);
		for (int i = 0; i < numberOfObjects; i++) {
			listBox2->Items->Add(thinnesses[i]);
		}
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		int k = System::Convert::ToInt32(textBox1->Text);

	}
	private: System::Void saveToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		long new_size;
		BYTE* display_imge = ConvertIntensityToBMP(segmanted, Width, Height, &new_size);
		output = L"C://resimler//segmented.bmp";
		SaveBMP(display_imge, Width, Height, new_size, output);

		delete[] display_imge;
	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		farea = 0;
		fthinness = 0;
		for (int i = 0; i < numberOfObjects; i++) {
			farea += areas[i];
			fthinness += thinnesses[i];
		}
		farea = farea / numberOfObjects;
		fthinness = fthinness / numberOfObjects;
		richTextBox1->AppendText("Fasulye\n"+System::Convert::ToString(farea)+" "+ System::Convert::ToString(fthinness)+"\n");
	}
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
		narea = 0;
		nthinness = 0;
		for (int i = 0; i < numberOfObjects; i++) {
			narea += areas[i];
			nthinness += thinnesses[i];
		}
		narea = narea / numberOfObjects;
		nthinness = nthinness / numberOfObjects;
		richTextBox1->AppendText("Nohut\n" + System::Convert::ToString(narea) + " " + System::Convert::ToString(nthinness) + "\n");
	}
	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
		marea = 0;
		mthinness = 0;
		for (int i = 0; i < numberOfObjects; i++) {
			marea += areas[i];
			mthinness += thinnesses[i];
		}
		marea = marea / numberOfObjects;
		mthinness = mthinness / numberOfObjects;
		richTextBox1->AppendText("Mercimek\n" + System::Convert::ToString(marea) + " " + System::Convert::ToString(mthinness) + "\n");
	}
	private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
		for (int i = 0; i < numberOfObjects; i++) {
			listBox1->Items->RemoveAt(0);
			listBox2->Items->RemoveAt(0);
		}
	}
	private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
		fas = 0;
		noh = 0;
		mer = 0;
		int df,dn,dm;
		classified = new int[numberOfObjects];
		for (int i = 0; i < numberOfObjects; i++) {
			df = sqrt(pow(farea - areas[i], 2) + pow(fthinness - thinnesses[i], 2));
			dn = sqrt(pow(narea - areas[i], 2) + pow(nthinness - thinnesses[i], 2));
			dm = sqrt(pow(marea - areas[i], 2) + pow(mthinness - thinnesses[i], 2));

			if (df < dn&&df < dm) {
				classified[i] = 0;
				fas++;
			}
			else if (dn < df&&dn < dm) {
				classified[i] = 1;
				noh++;
			}
			else if (dm < df&&dm < dn) {
				classified[i] = 2;
				mer++;
			}
		}
		richTextBox2->AppendText("Number of Beans: " + System::Convert::ToString(fas) + "\n");
		richTextBox2->AppendText("Number of Chickpeas: " + System::Convert::ToString(noh) + "\n");
		richTextBox2->AppendText("Number of Lentils: " + System::Convert::ToString(mer) + "\n");
	}
	private: System::Void prosedureOneToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		//intesity
		{
			Raw_Intensity = ConvertBMPToIntensity(buffer, Width, Height);
			// picture
			{
				Bitmap^ surface = gcnew Bitmap(Width, Height);
				pictureBox1->Image = surface;
				Color c;
				int temp;
				for (unsigned int row = 0; row < Height; row++) {
					for (unsigned int column = 0; column < Width; column++) {
						temp = row * Width + column;
						c = Color::FromArgb(Raw_Intensity[temp], Raw_Intensity[temp], Raw_Intensity[temp]);
						surface->SetPixel(column, row, c);
					}
				}
			}
		}
		//segmentation
		{
			int* Histogram = getHistogram(Raw_Intensity, Width, Height);
			segmanted = KMeans(Histogram, Raw_Intensity, Width*Height, 2);
			// picture
			{
				Bitmap^ surface = gcnew Bitmap(Width, Height);
				pictureBox1->Image = surface;
				Color c;
				int temp;
				for (unsigned int row = 0; row < Height; row++) {
					for (unsigned int column = 0; column < Width; column++) {
						temp = row * Width + column;
						c = Color::FromArgb(segmanted[temp], segmanted[temp], segmanted[temp]);
						surface->SetPixel(column, row, c);
					}
				}
			}
		}
		//morphological open
		{
			segmanted = Erosion(segmanted, Width, Height, 1);
			segmanted = Dilation(segmanted, Width, Height, 1);
			// picture
			{
				Bitmap^ surface = gcnew Bitmap(Width, Height);
				pictureBox1->Image = surface;
				Color c;
				int temp;
				for (unsigned int row = 0; row < Height; row++) {
					for (unsigned int column = 0; column < Width; column++) {
						temp = row * Width + column;
						c = Color::FromArgb(segmanted[temp], segmanted[temp], segmanted[temp]);
						surface->SetPixel(column, row, c);
					}
				}
			}
		}
		//morphological close
		{
			segmanted = Dilation(segmanted, Width, Height, 1);
			segmanted = Erosion(segmanted, Width, Height, 1);

			// picture
			{
				Bitmap^ surface = gcnew Bitmap(Width, Height);
				pictureBox1->Image = surface;
				Color c;
				int temp;
				for (unsigned int row = 0; row < Height; row++) {
					for (unsigned int column = 0; column < Width; column++) {
						temp = row * Width + column;
						c = Color::FromArgb(segmanted[temp], segmanted[temp], segmanted[temp]);
						surface->SetPixel(column, row, c);
					}
				}
			}
		}
		//connected component analysis
		{
			label1->Visible = true;
			tags = Create_Tags(segmanted, Width, Height, 8);
			sortedTags = Sort_Tags(tags, Width, Height);
			numberOfObjects = Count_Tags(sortedTags, imgSize);
			label1->Text = System::Convert::ToString(numberOfObjects);
			tagList = Create_TagList(sortedTags, numberOfObjects, imgSize);
		}
		//area extraction
		{
			areas = Area_Extraction(tags, tagList, numberOfObjects, imgSize);
			for (int i = 0; i < numberOfObjects; i++) {
				listBox1->Items->Add(areas[i]);
			}
		}
		//thinnness extraction
		{
			perimeters = Perimeter_Extraction(segmanted, Width, Height);
			thinnesses = Thinness_Extraction(areas, perimeters, numberOfObjects);
			for (int i = 0; i < numberOfObjects; i++) {
				listBox2->Items->Add(thinnesses[i]);
			}
		}
	}
	private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) {
		segmanted = Erosion(segmanted, Width, Height, 1);
		segmanted = Dilation(segmanted, Width, Height, 1);
		segmanted = Dilation(segmanted, Width, Height, 1);
		segmanted = Erosion(segmanted, Width, Height, 1);
		boundary = Boundary_Extraction(segmanted, Width, Height);
		show = ShowClass(Raw_Intensity, boundary, tags, tagList, numberOfObjects, imgSize, 0, classified);
		// picture
		{
			Bitmap^ surface = gcnew Bitmap(Width, Height);
			pictureBox1->Image = surface;
			Color c;
			int temp;
			for (unsigned int row = 0; row < Height; row++) {
				for (unsigned int column = 0; column < Width; column++) {
					temp = row * Width + column;
					c = Color::FromArgb(show[temp], show[temp], show[temp]);
					surface->SetPixel(column, row, c);
				}
			}
		}
	}
	private: System::Void button8_Click(System::Object^  sender, System::EventArgs^  e) {
		segmanted = Erosion(segmanted, Width, Height, 1);
		segmanted = Dilation(segmanted, Width, Height, 1);
		segmanted = Dilation(segmanted, Width, Height, 1);
		segmanted = Erosion(segmanted, Width, Height, 1);
		boundary = Boundary_Extraction(segmanted, Width, Height);
		show = ShowClass(Raw_Intensity, boundary, tags, tagList, numberOfObjects, imgSize, 1, classified);
		// picture
		{
			Bitmap^ surface = gcnew Bitmap(Width, Height);
			pictureBox1->Image = surface;
			Color c;
			int temp;
			for (unsigned int row = 0; row < Height; row++) {
				for (unsigned int column = 0; column < Width; column++) {
					temp = row * Width + column;
					c = Color::FromArgb(show[temp], show[temp], show[temp]);
					surface->SetPixel(column, row, c);
				}
			}
		}
	}
	private: System::Void button9_Click(System::Object^  sender, System::EventArgs^  e) {
		segmanted = Erosion(segmanted, Width, Height, 1);
		segmanted = Dilation(segmanted, Width, Height, 1);
		segmanted = Dilation(segmanted, Width, Height, 1);
		segmanted = Erosion(segmanted, Width, Height, 1);
		boundary = Boundary_Extraction(segmanted, Width, Height);
		show = ShowClass(Raw_Intensity, boundary, tags, tagList, numberOfObjects, imgSize, 2, classified);
		// picture
		{
			Bitmap^ surface = gcnew Bitmap(Width, Height);
			pictureBox1->Image = surface;
			Color c;
			int temp;
			for (unsigned int row = 0; row < Height; row++) {
				for (unsigned int column = 0; column < Width; column++) {
					temp = row * Width + column;
					c = Color::FromArgb(show[temp], show[temp], show[temp]);
					surface->SetPixel(column, row, c);
				}
			}
		}
	}
};
}
