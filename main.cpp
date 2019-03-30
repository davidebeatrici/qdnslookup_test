#include <QCoreApplication>
#include <QDebug>
#include <QDnsLookup>

class Resolver : public QObject
{
	Q_OBJECT

	public:
		Resolver()
		{
			qdl = new QDnsLookup(this);
			connect(qdl, SIGNAL(finished()), this, SLOT(resolved()));

			qdl->setType(QDnsLookup::SRV);
			qdl->setName("_xmpp-client._tcp.gmail.com"); // Took from https://doc.qt.io/qt-5/qdnslookup.html#details
			qdl->lookup();
		}

		~Resolver()
		{
			delete qdl;
		}

	public slots:
		void resolved()
		{
			if (qdl->error() == QDnsLookup::NoError) {
				qInfo() << "No errors!";
			} else {
				qWarning() << qdl->errorString();
			}
		}

	private:
		QDnsLookup *qdl;
};

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	Resolver resolver;

	return a.exec();
}

#include "main.moc"
