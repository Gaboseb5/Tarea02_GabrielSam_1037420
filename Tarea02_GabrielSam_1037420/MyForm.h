#pragma once
#include <iostream>
#include<stdlib.h>
#include <cstdlib>
#include<time.h>

void Imprime_Pista(char A[], int);
int Avanza_Liebre(int);
int Avanza_Tortuga(int);

namespace Tarea02GabrielSam1037420 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btniniciar;
	protected:
	private: System::Windows::Forms::RichTextBox^ txtimprimir;
	private: System::Windows::Forms::Button^ btnlimpiar;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->btniniciar = (gcnew System::Windows::Forms::Button());
			this->txtimprimir = (gcnew System::Windows::Forms::RichTextBox());
			this->btnlimpiar = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btniniciar
			// 
			this->btniniciar->BackColor = System::Drawing::Color::Transparent;
			this->btniniciar->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btniniciar->Location = System::Drawing::Point(531, 70);
			this->btniniciar->Name = L"btniniciar";
			this->btniniciar->Size = System::Drawing::Size(131, 36);
			this->btniniciar->TabIndex = 0;
			this->btniniciar->Text = L"Iniciar carrera";
			this->btniniciar->UseVisualStyleBackColor = false;
			this->btniniciar->Click += gcnew System::EventHandler(this, &MyForm::btniniciar_Click);
			// 
			// txtimprimir
			// 
			this->txtimprimir->Location = System::Drawing::Point(43, 59);
			this->txtimprimir->Name = L"txtimprimir";
			this->txtimprimir->Size = System::Drawing::Size(398, 374);
			this->txtimprimir->TabIndex = 1;
			this->txtimprimir->Text = L"";
			// 
			// btnlimpiar
			// 
			this->btnlimpiar->BackColor = System::Drawing::Color::Transparent;
			this->btnlimpiar->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnlimpiar->Location = System::Drawing::Point(531, 130);
			this->btnlimpiar->Name = L"btnlimpiar";
			this->btnlimpiar->Size = System::Drawing::Size(131, 36);
			this->btnlimpiar->TabIndex = 2;
			this->btnlimpiar->Text = L"Limpiar";
			this->btnlimpiar->UseVisualStyleBackColor = false;
			this->btnlimpiar->Click += gcnew System::EventHandler(this, &MyForm::btnlimpiar_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(709, 547);
			this->Controls->Add(this->btnlimpiar);
			this->Controls->Add(this->txtimprimir);
			this->Controls->Add(this->btniniciar);
			this->Name = L"MyForm";
			this->Text = L"Carrera";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void btnlimpiar_Click(System::Object^ sender, System::EventArgs^ e) {
		txtimprimir->Clear();
	}
		   
		   


	private: System::Void btniniciar_Click(System::Object^ sender, System::EventArgs^ e) {

	
		const int Tamano_Arreglo = 70;

		txtimprimir->Text="\n\nESTE PROGRAMA SIMULA LA MEMORABLE CARRERA ENTRE LA ";
		txtimprimir->Text = "LIEBRE (H) Y LA TORTUGA (T)!";
		txtimprimir->Text = "AMBAS INICAN EMPATADAS (E) EN LA CASILLA 1.";
		txtimprimir->Text = "\t\t\tHAGAN SUS APUESTAS! ";

		srand(time(0));


		char Pista[Tamano_Arreglo + 1] = { 0, 'E', 0, 0 };
		int Posicion_Tortuga = 1;
		int tortuga = 1;
		int Posicion_Liebre = 1;
		int liebre = 1;
		int centinela = 0;
		int numero;
		int contador = 1;
		numero = rand() % (71 - 1);
		Imprime_Pista(Pista, Tamano_Arreglo);


		while (0 == centinela)
		{ // Abre while

			txtimprimir->Text= txtimprimir->Text +numero;

			txtimprimir->Text = "\t\t\t\tBANG!";
			txtimprimir->Text = "\t\t\t Y ARRANCAN!";

			for (int x = 1; x <= Tamano_Arreglo; x++)
			{
				Pista[x] = 0;
			}

			Posicion_Tortuga = Avanza_Tortuga(Posicion_Tortuga);
			tortuga = Posicion_Tortuga;
			Posicion_Liebre = Avanza_Liebre(Posicion_Liebre);
			liebre = Posicion_Liebre;
			txtimprimir->Text = txtimprimir->Text + Posicion_Liebre;
			txtimprimir->Text = txtimprimir->Text + Posicion_Tortuga ;
			// Descomentar


			if ((1 <= Posicion_Liebre) && (Tamano_Arreglo > Posicion_Liebre))
			{ // Abre if
				Pista[Posicion_Liebre] = 'H';
			} // Cierra if

			if (1 > Posicion_Liebre)
			{
				txtimprimir->Text = "Menor ";
				// Descomentar

				Posicion_Liebre = 1;
				Pista[Posicion_Liebre] = 'H';
			}
			if ((Posicion_Tortuga >= 1) && (Tamano_Arreglo > Posicion_Liebre))
			{ // Abre if
				txtimprimir->Text = "entro a if ";
				// Descomentar

				if (Posicion_Tortuga == Posicion_Liebre)
				{
					Pista[Posicion_Tortuga] = 'E';
				}
				else
				{
					Pista[Posicion_Tortuga] = 'T';
				}
			} // Cierra if

			if (Posicion_Tortuga < 1)
			{
				Posicion_Tortuga = 1;
				if (1 == Posicion_Liebre)
					Pista[Posicion_Tortuga] = 'E';
				else
					Pista[Posicion_Tortuga] = 'T';
			}

			if (Posicion_Liebre >= Tamano_Arreglo)
			{ // Abre if
				centinela = -1;
				if (Posicion_Tortuga > Tamano_Arreglo)
					txtimprimir->Text = "\nQUE CIERRE! LA LIEBRE Y LA TORTUGA EMPATARON! ";
				else
					txtimprimir->Text = "\nNI HABLAR, GANO LA LIEBRE! ";

				Pista[Tamano_Arreglo] = 'L';
			} // Cierra if


			if (Posicion_Tortuga >= Tamano_Arreglo)
			{ // Abre if
				centinela = -1;
				if (Posicion_Liebre < Tamano_Arreglo)
				{
					Pista[Tamano_Arreglo] = 'T';
					txtimprimir->Text = "\nZANAHORIA Y LECHUGAS FRESCAS PARA LA TORTUGA QUE SE LLEVA ";
					txtimprimir->Text = "LA COMPETENCIA! BRAVO! ";

				}
				else
				{
					Pista[Tamano_Arreglo] = 'E';
					txtimprimir->Text = "\nEN UN DRAMATICO CIERRE LA TORTUGA Y LA LIEBRE EMPATAN! " ;
				}
			} // Cierra if


			Imprime_Pista(Pista, Tamano_Arreglo);

			if ('E' == Pista[Posicion_Tortuga])
			{ // Abre if

				switch (contador)

				{ // Abrre switch
				case 1:
				{
					txtimprimir->Text = "\aOUCH! LA TORTUGA TRAMPOSA HA MORDIDO A LA LIEBRE! ";
					contador++;
					break;
				}
				case 2:
				{
					txtimprimir->Text = "\aOUCH! NO SE VALE! LA TORTUGA VUELVE A HACERLO!";
					contador++;
					break;
				}
				case 3:
				{
					txtimprimir->Text = "\aOUCH!ESTO YA ES COSTUMBRE, VUELVEN A MORDER A LA LIEBRE!";
					contador++;
					break;
				}
				default:
				{
					txtimprimir->Text = "\aOUCH! PERO DE QUE SE TRATA?!!";
					break;
				}
				} // cierra switch

			} // Cierra if

		} // Cierra centinela



	}

	void Imprime_Pista(char A[], int n)

	{ // Abre Imprime pista

		txtimprimir->Text="***";
		for (int i = 1; i <= n; i++)
		{ // Abre for
			if (0 == A[i])
				txtimprimir->Text = " ";
			else
				txtimprimir->Text = txtimprimir->Text + A[i];
		} // Cierra for

		txtimprimir->Text = "****";
		txtimprimir->Text;



	} // Cierra Imprime pista


	/////////////////////////////////////////////////////////////////////
	// INICIA AVANZA LIEBRE
	////////////////////////////////////////////////////////////////////

	int Avanza_Liebre(int l)

	{ // Abre Avanza Liebre
		srand(time(0));
		int ruleta;
		ruleta = 1 + rand() % 10;

		txtimprimir->Text = "ruleta = " + ruleta;
		//quitar este comentario para ver como se mueve esta variable

		if (2 >= ruleta)
			return l;

		if (4 >= ruleta)
			return (l + 9);

		if (5 >= ruleta)
			return l - 12;

		if (8 >= ruleta)
			return l + 1;

		if (10 >= ruleta)
			return l - 2;

	} // Cierra Avanza Liebre



	///////////////////////////////////////////////////////////////////
	// INICIA AVANZA TORTUGA
	////////////////////////////////////////////////////////////////////

	int Avanza_Tortuga(int t)
	{ // Abre Avanza tortuga
		srand(time(0));
		int dados = 1 + rand() % 10;

		txtimprimir->Text = "dados = " + dados;
		// Descomentar para ver la variable dados

		if (5 >= dados)
			return (t + 3);

		if (7 >= dados)
			return (t - 6);

		if (10 >= dados)
			return (t + 1);

	} // Cierra Avanza tortuga
	
	};
}
